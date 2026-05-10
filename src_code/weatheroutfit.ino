#include <Wire.h>
#include <SHTSensor.h>
#include <LTR303.h>

SHTSensor sht;
LTR303 light;

unsigned char gain = 0;
unsigned char integrationTime = 0;
unsigned char measurementRate = 3;

void afficherTenue(float temp, float hum, float lux) {

  bool ensoleille = (lux >= 10000);
  bool humide = (hum > 60);
  bool tresHumide = (hum > 80);

  // CANICULE > 36°C
  if (temp > 36) {
    if (!humide) {
      Serial.println(F("CANICULE SECHE"));
      Serial.println(F("Haut: Debardeur"));
      Serial.println(F("Bas: Short"));
      Serial.println(F("Chaussures: Sandales"));
      Serial.println(F("Acc: Chapeau+lunettes+creme"));
    } else {
      Serial.println(F("CANICULE HUMIDE"));
      Serial.println(F("Haut: Debardeur leger"));
      Serial.println(F("Bas: Short"));
      Serial.println(F("Chaussures: Sandales"));
      Serial.println(F("Acc: Chapeau+eau. DANGER !"));
    }
    return;
  }

  // TRES CHAUD 26-35°C
  if (temp >= 26) {
    if (ensoleille && !humide) {
      Serial.println(F("TRES CHAUD ENSOLEILLE"));
      Serial.println(F("Haut: T-shirt"));
      Serial.println(F("Bas: Short"));
      Serial.println(F("Chaussures: Sandales"));
      Serial.println(F("Acc: Casquette+lunettes+creme"));
    } else if (ensoleille && humide) {
      Serial.println(F("TRES CHAUD ENSOLEILLE HUMIDE"));
      Serial.println(F("Haut: T-shirt"));
      Serial.println(F("Bas: Short"));
      Serial.println(F("Chaussures: Basket"));
      Serial.println(F("Acc: Casquette+creme"));
    } else if (!ensoleille && !humide) {
      Serial.println(F("TRES CHAUD NUAGEUX"));
      Serial.println(F("Haut: T-shirt"));
      Serial.println(F("Bas: Short"));
      Serial.println(F("Chaussures: Basket"));
      Serial.println(F("Acc: Rien"));
    } else {
      Serial.println(F("TRES CHAUD HUMIDE"));
      Serial.println(F("Haut: T-shirt respirant"));
      Serial.println(F("Bas: Short"));
      Serial.println(F("Chaussures: Basket"));
      Serial.println(F("Acc: Coupe-vent dans sac"));
    }
    return;
  }

  // CHAUD 18-25°C
  if (temp >= 18) {
    if (ensoleille && !humide) {
      Serial.println(F("CHAUD ENSOLEILLE"));
      Serial.println(F("Haut: T-shirt"));
      Serial.println(F("Bas: Jean leger"));
      Serial.println(F("Chaussures: Basket"));
      Serial.println(F("Acc: Lunettes de soleil"));
    } else if (ensoleille && humide) {
      Serial.println(F("CHAUD ENSOLEILLE HUMIDE"));
      Serial.println(F("Haut: T-shirt + coupe-vent"));
      Serial.println(F("Bas: Jean"));
      Serial.println(F("Chaussures: Basket"));
      Serial.println(F("Acc: Lunettes+parapluie"));
    } else if (!ensoleille && !humide) {
      Serial.println(F("CHAUD NUAGEUX"));
      Serial.println(F("Haut: T-shirt + veste legere"));
      Serial.println(F("Bas: Jean"));
      Serial.println(F("Chaussures: Basket"));
      Serial.println(F("Acc: Veste dans sac"));
    } else if (!tresHumide) {
      Serial.println(F("CHAUD HUMIDE"));
      Serial.println(F("Haut: T-shirt + impermeable"));
      Serial.println(F("Bas: Jean"));
      Serial.println(F("Chaussures: Basket imp."));
      Serial.println(F("Acc: Parapluie"));
    } else {
      Serial.println(F("CHAUD TRES HUMIDE"));
      Serial.println(F("Haut: T-shirt + impermeable"));
      Serial.println(F("Bas: Jean impermeable"));
      Serial.println(F("Chaussures: Bottes pluie"));
      Serial.println(F("Acc: Parapluie"));
    }
    return;
  }

  // DOUX 11-17°C
  if (temp >= 11) {
    if (ensoleille && !humide) {
      Serial.println(F("DOUX ENSOLEILLE"));
      Serial.println(F("Haut: T-shirt + gilet"));
      Serial.println(F("Bas: Jean"));
      Serial.println(F("Chaussures: Basket"));
      Serial.println(F("Acc: Lunettes de soleil"));
    } else if (ensoleille && humide) {
      Serial.println(F("DOUX ENSOLEILLE HUMIDE"));
      Serial.println(F("Haut: Pull + coupe-vent"));
      Serial.println(F("Bas: Jean"));
      Serial.println(F("Chaussures: Basket imp."));
      Serial.println(F("Acc: Echarpe"));
    } else if (!ensoleille && !humide) {
      Serial.println(F("DOUX NUAGEUX"));
      Serial.println(F("Haut: Pull ou sweat"));
      Serial.println(F("Bas: Jean"));
      Serial.println(F("Chaussures: Basket"));
      Serial.println(F("Acc: Echarpe legere"));
    } else if (!tresHumide) {
      Serial.println(F("DOUX HUMIDE"));
      Serial.println(F("Haut: Pull + impermeable"));
      Serial.println(F("Bas: Jean"));
      Serial.println(F("Chaussures: Basket imp."));
      Serial.println(F("Acc: Parapluie"));
    } else {
      Serial.println(F("DOUX TRES HUMIDE"));
      Serial.println(F("Haut: Pull + impermeable"));
      Serial.println(F("Bas: Jean impermeable"));
      Serial.println(F("Chaussures: Bottes pluie"));
      Serial.println(F("Acc: Parapluie"));
    }
    return;
  }

  // FRAIS 1-10°C
  if (temp >= 1) {
    if (ensoleille && !humide) {
      Serial.println(F("FRAIS ENSOLEILLE"));
      Serial.println(F("Haut: Pull + veste"));
      Serial.println(F("Bas: Jean epais"));
      Serial.println(F("Chaussures: Chaussures fermees"));
      Serial.println(F("Acc: Echarpe + bonnet"));
    } else if (ensoleille && humide) {
      Serial.println(F("FRAIS ENSOLEILLE HUMIDE"));
      Serial.println(F("Haut: Pull + impermeable"));
      Serial.println(F("Bas: Jean epais"));
      Serial.println(F("Chaussures: Chaussures imp."));
      Serial.println(F("Acc: Echarpe+bonnet+parapluie"));
    } else if (!ensoleille && !humide) {
      Serial.println(F("FRAIS NUAGEUX"));
      Serial.println(F("Haut: Pull + manteau leger"));
      Serial.println(F("Bas: Jean epais"));
      Serial.println(F("Chaussures: Chaussures fermees"));
      Serial.println(F("Acc: Echarpe + bonnet"));
    } else {
      Serial.println(F("FRAIS HUMIDE"));
      Serial.println(F("Haut: Pull + impermeable"));
      Serial.println(F("Bas: Jean epais"));
      Serial.println(F("Chaussures: Bottes"));
      Serial.println(F("Acc: Echarpe+bonnet+parapluie"));
    }
    return;
  }

  // GRAND FROID < 1°C
  if (ensoleille && !humide) {
    Serial.println(F("GRAND FROID ENSOLEILLE"));
  } else if (ensoleille && humide) {
    Serial.println(F("GRAND FROID ENSOLEILLE HUMIDE"));
  } else if (!ensoleille && !humide) {
    Serial.println(F("GRAND FROID SEC"));
  } else {
    Serial.println(F("GRAND FROID HUMIDE"));
  }
  Serial.println(F("Haut: Pull + manteau chaud"));
  Serial.println(F("Bas: Pantalon chaud"));
  Serial.println(F("Chaussures: Bottes chaudes"));
  Serial.println(F("Acc: Echarpe+bonnet+gants"));
}

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println(F("--- Projet CSF : Tenue Meteo ---"));

  if (sht.init()) {
    Serial.println(F("Capteur SHT : OK"));
  } else {
    Serial.println(F("Capteur SHT : Erreur !"));
  }

  if (light.begin()) {
    light.setControl(gain, false, true);
    light.setMeasurementRate(integrationTime, measurementRate);
    light.setPowerUp();
    Serial.println(F("Capteur LTR303 : OK"));
  } else {
    Serial.println(F("Capteur LTR303 : Erreur !"));
  }
}

void loop() {
  float temp = 0, hum = 0;
  double lux = 0;

  if (sht.readSample()) {
    temp = sht.getTemperature();
    hum  = sht.getHumidity();
  }

  unsigned int rawCH0, rawCH1;
  if (light.getData(rawCH0, rawCH1)) {
    light.getLux(gain, integrationTime, rawCH0, rawCH1, lux);
  }

  Serial.println(F("=============================="));
  Serial.print(F("Temp      : ")); Serial.print(temp, 1); Serial.println(F(" C"));
  Serial.print(F("Humidite  : ")); Serial.print(hum,  1); Serial.println(F(" %"));
  Serial.print(F("Luminosite: ")); Serial.print((int)lux); Serial.println(F(" lux"));
  Serial.println(F("------------------------------"));
  Serial.println(F("TENUE RECOMMANDEE :"));

  afficherTenue(temp, hum, (float)lux);

  Serial.println(F("=============================="));
  delay(3000);
}