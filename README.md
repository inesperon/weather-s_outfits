*Projet réalisé par Quentin Ovion, Martin Vaillant et Inès Peron.*

# 🌤️ Weather's Outfit - Station Météo Connectée

> **Optimiser l'habillement des enfants grâce à l'IoT.**

Ce projet utilise une carte Arduino et des capteurs de précision pour analyser les conditions climatiques locales (luminosité, humidité, température) afin de suggérer la tenue vestimentaire idéale parmi 24 solutions possibles.

---

## 📝 1. Présentation du Projet
Le passage du temps et les variations météorologiques locales rendent souvent difficile le choix de la tenue adaptée pour un enfant. **Weather's Outfit** répond à cette problématique en proposant une station météo domestique qui ne se contente pas de donner des chiffres, mais interprète les données pour offrir un conseil concret.

### Objectifs :
* **Fiabilité :** Mesures locales précises (jardin, balcon) plutôt que des prévisions globales.
* **Pédagogie :** Aider l'enfant à devenir autonome dans ses choix quotidiens.
* **Simplicité :** Une interface web claire qui affiche directement la tenue à porter.

---

## 🛠️ 2. Liste du Matériel (Hardware)

Le projet s'articule autour de composants basse consommation permettant une collecte de données constante.

| Composant | Rôle |
| :--- | :--- |
| **Carte Arduino / UCA** | Cœur du système (Traitement des données et logique logicielle). |
| **Capteur SHTC3** | Mesure précise de la **température** et de l'**humidité** relative. |
| **Capteur LTR-303** | Mesure de la **luminosité** (Lux) pour détecter l'ensoleillement. |
| **Module Radio/WiFi** | Transmission des informations vers le site web. |

---

## 🧠 3. Intelligence et Application
Le système analyse 3 paramètres clés pour déterminer la tenue :
1. **Chaleur :** Pour choisir entre manches courtes, manches longues ou gros manteau.
2. **Humidité :** Pour anticiper le besoin de vêtements de pluie.
3. **Luminosité :** Pour recommander des accessoires (lunettes de soleil, casquette).

**Résultat :** Le site web génère une recommandation parmi **24 combinaisons**, dont 8 sont spécifiquement optimisées pour les activités d'un enfant en extérieur.

---

## 📅 4. Planning de Réalisation

| Séance | Date | Objectif |
| :--- | :--- | :--- |
| **Séance 1** | 3-9 avril | Formation équipe + cahier des charges. |
| **Séance 2** | 13-16 avril | Formation Github + démarrage projet |
| **Séance 3** | 20-23 avril | Développement capteurs |
| **Séance 4** | 27-30 avril | Présentation intermédiaire |
| **Séance 5** | 4-7 mai | Intégration LoRa |
| **Séance 6** | 11-14 mai | Tests et améliorations |
| **Séance 7** | 18-21 mai | Finalisation démonstrateur |
| **Séance 8** | 26-28 mai | Présentation finale + démo |

---

## 📂 5. Utilisation dans le Projet
Ce dépôt GitHub contient :
* `src_code/` : Le code source Arduino (.ino) pour la lecture des capteurs.
* `web/` : Les fichiers du site web pour l'affichage des solutions.
* `docs/` : Les schémas de câblage et la documentation technique.

Ce document sert de référence pour comprendre la structure du projet, faciliter la maintenance du code et permettre à d'autres développeurs de reproduire la station météo.

---

