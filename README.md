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

| Phase | Activité | Objectif |
| :--- | :--- | :--- |
| **Phase 1** | Conception | Étude des seuils météo et définition des 24 scénarios. |
| **Phase 2** | Hardware | Câblage et tests unitaires des capteurs (I2C). |
| **Phase 3** | Développement | Programmation de l'algorithme de décision sur Arduino. |
| **Phase 4** | Intégration Web | Création de l'interface visuelle et réception des données. |
| **Phase 5** | Déploiement | Tests finaux et rédaction de la documentation GitHub. |

---

## 📂 5. Utilisation dans le Projet
Ce dépôt GitHub contient :
* `src_code/` : Le code source Arduino (.ino) pour la lecture des capteurs.
* `web/` : Les fichiers du site web pour l'affichage des solutions.
* `docs/` : Les schémas de câblage et la documentation technique.

Ce document sert de référence pour comprendre la structure du projet, faciliter la maintenance du code et permettre à d'autres développeurs de reproduire la station météo.

---

