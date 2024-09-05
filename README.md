# Mini Compilateur

Ce projet est un mini-compilateur implémenté en **C** utilisant **Flex** et **Bison** pour réaliser les différentes phases de la compilation. Le compilateur comprend l'analyse lexicale, l'analyse syntactico-sémantique, ainsi que la gestion parallèle de la table des symboles et le traitement des erreurs.

## Fonctionnalités

- **Analyse Lexicale** : Utilisation de **Flex** pour effectuer la reconnaissance des tokens dans le code source.
- **Analyse Syntactico-Sémantique** : Utilisation de **Bison** (ou **Yacc**) pour analyser la syntaxe du code et vérifier les règles sémantiques.
- **Gestion des Tables de Symboles** : Traitement parallèle pour gérer les tables de symboles, permettant une gestion efficace des variables et fonctions.
- **Gestion des Erreurs** : Traitement des erreurs lexicales, syntaxiques et sémantiques avec des messages détaillés.

## Technologies Utilisées

- **Langage C** : Langage de programmation principal pour le compilateur.
- **Flex** : Outil pour générer des analyseurs lexicaux.
- **Bison** : Outil pour générer des analyseurs syntaxiques.
- **Yacc** : Alternative à Bison pour la génération d'analyseurs syntaxiques (utilisé en combinaison avec Bison).
- **Linux** : Système d'exploitation pour le développement et la compilation.

## Installation

### Prérequis

- **Flex** et **Bison** installés sur votre système Linux.
- **GCC** pour la compilation du code C.

### Étapes d'installation

1. **Cloner le dépôt** :
   ```bash
   git clone https://github.com/nerminebgr/Compiler.git
   cd Compiler
   Générer les fichiers d'analyse :
   flex scanner.lex
   bison -d parser.y
   gcc -o compiler lex.yy.c parser.tab.c -lfl
   ./compiler test.txt

