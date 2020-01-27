# Ecosystem simulation

![release](https://img.shields.io/badge/release-v1.1-blueviolet)
![language](https://img.shields.io/badge/language-C%2B%2B-0052cf)
![library](https://img.shields.io/badge/library-SDL2-00cf2c)
![size](https://img.shields.io/badge/size-76%20Mo-f12222)
![license](https://img.shields.io/badge/license-CC--0-0bb9ec)

<br/>

Ce dépôt contient le code source d'un programme simulant différents types d'êtres vivants, des plantes, des proies et des prédateurs afin de créer un écosystème.

<br/>

<p align="center">
	<img src="https://i.imgur.com/DgQEcKJ.png" width="700">
</p>

<br/>

# Utilisation

Vous trouverez dans le fichier [main.cpp](https://github.com/angeluriot/Ecosystem_simulation/blob/master/sources/main.cpp) le morceau
de code permettant de modifier les différents paramètres de la simulation :

```cpp

// ------------------------- Paramètres de la simulation -------------------------

int world_width = 320;              // Largeur du monde (en cases)
int world_height = 180;             // Hateur du monde (en cases)
int zoom = 6;                       // Taille des cases (en pixels)

int nb_plants = 160;                // Nombre de plantes au début
int growth_rate = 15;               // Vitesse de l'évolution des plantes (en pourcents)

int nb_preys = 160;                 // Nombre de proies au début
int prey_time_no_eat_max = 30;      // Temps que tient une proie sans manger
int prey_nb_eat_kid = 15;           // Nombre de plantes qu'une proie doit manger pour faire un enfant

int nb_predators = 20;              // Nombre de prédators au début
int predator_time_no_eat_max = 60;  // Temps que tient un prédateur sans manger
int predator_nb_eat_kid = 25;       // Nombre de proies qu'un prédateur doit manger pour faire un enfant

int frame_rate_max = 144;        // FPS maximum (en images par seconde)

// -------------------------------------------------------------------------------

```

<br/>

# Installation

* Si vous possédez déjà le compilateur **MinGW** et de quoi utiliser un Makefile
sur Windows, il vous suffit de télécharger l'intégralité du dépôt et de faire la commande **`make`** à la racine du projet.

<br/>

* Si ce n'est pas le cas, cliquez sur l'aide dont vous avez besoin :

  * [Mode d'emploi pour installer **MinGW**.](#installer-mingw)

  * [Mode d'emploi pour utiliser **`make`**.](#utiliser-make)

<br/>

# Releases

Vous pouvez tester directement le programme sans installation en consultant les [Releases](https://github.com/angeluriot/Ecosystem_simulation/releases)

<br/>

# Crédits

* [Angel Uriot](https://github.com/angeluriot) : Créateur du projet.

* [ShiroW](https://github.com/mbourand) : Aide à l'optimisation.

<br/>

# Installer MinGW

Dans un premier temps, téléchargez l'installeur de **MinGW** en utilisant ce lien :&nbsp; [[télécharger MinGW]](http://www.mediafire.com/file/zeac28nmd3rh03m/mingw-get-setup.exe/file)

<br/>

En ouvrant l'installeur, vous devriez avoir cette fenêtre :

<br/>

<p align="center">
	<img src="https://i.imgur.com/jMztODh.png" width="400">
</p>

<br/>

<br/>

Cliquez sur **Install**, puis, après avoir choisi le répertoire d'installation, copiez le chemin, ce sera utile pour la suite :

<br/>

<p align="center">
	<img src="https://i.imgur.com/bhKNOqt.png" width="400">
</p>

<br/>

<br/>

Après avoir fini l'installation, la fenêtre **MinGW Installation Manager** va se lancer *(si ce n'est pas le cas, ouvrez-là avec la
recherche Windows)*, cliquez ensuite sur **All Packages** en haut à gauche :

<br/>

<p align="center">
	<img src="https://i.imgur.com/qvcvS4C.png" width="300">
</p>

<br/>

<br/>

Puis descendez dans la liste des modules à installer jusqu'à arriver à **mingw32-gcc-bin** et sélectionnez tous les modules commençant
par **mingw32-gcc** :

<br/>

<p align="center">
	<img src="https://i.imgur.com/3wgbhyt.png" width="500">
</p>

<br/>

<br/>

Enfin, faites **Apply Changes** :

<br/>

<p align="center">
	<img src="https://i.imgur.com/Ozr7IMX.png" width="300">
</p>

<br/>

<br/>

**MinGW** est maintenant intallé sur votre machine, la dernière chose à faire est d'ajouter une variable d'environnement. Allez
dans **Modifier les variables d'environnement système** à l'aide de la recherche Windows :

<br/>

<p align="center">
	<img src="https://i.imgur.com/8iJBkn6.png" width="300">
</p>

<br/>

<br/>

Puis dans **Variables d'environnement...** :

<br/>

<p align="center">
	<img src="https://i.imgur.com/Qd0iC8q.png" width="300">
</p>

<br/>

<br/>

Cherchez ensuite **Path** dans la liste du bas et faites **Modifier...** :

<br/>

<p align="center">
	<img src="https://i.imgur.com/dM1AJX3.png" width="500">
</p>

<br/>

<br/>

Enfin, ajoutez le chemin copié plus tôt suivi de **\bin** dans la liste :

<br/>

<p align="center">
	<img src="https://i.imgur.com/ReExJcG.png" width="500">
</p>

<br/>

<br/>

Et voilà ! Il vous faut maintenant de quoi utiliser `make`, si vous n'en avez pas, vous trouverez comment faire ici :

* [Mode d'emploi pour utiliser **`make`**.](#utiliser-make)

<br/>

# Utiliser make

Pour cela nous allons utiliser **GnuWin**, téléchargez l'installeur en utilisant ce lien :&nbsp; [[télécharger GnuWin]](http://www.mediafire.com/file/wqde0ge7cy62u8e/make-3.81.exe/file)

<br/>

En ouvrant l'installeur, vous devriez avoir cette fenêtre :

<br/>

<p align="center">
	<img src="https://i.imgur.com/aUCXBMj.png" width="400">
</p>

<br/>

<br/>

Cliquez sur **Next**, puis, après avoir choisi le répertoire d'installation, copiez le chemin, ce sera utile pour la suite :

<br/>

<p align="center">
	<img src="https://i.imgur.com/aoAfOSZ.png" width="400">
</p>

<br/>

<br/>

Une fois l'installation de **GnuWin** terminée, la dernière chose à faire est d'ajouter une variable d'environnement. Allez
dans **Modifier les variables d'environnement système** à l'aide de la recherche Windows :

<br/>

<p align="center">
	<img src="https://i.imgur.com/8iJBkn6.png" width="300">
</p>

<br/>

<br/>

Puis dans **Variables d'environnement...** :

<br/>

<p align="center">
	<img src="https://i.imgur.com/Qd0iC8q.png" width="300">
</p>

<br/>

<br/>

Cherchez ensuite **Path** dans la liste du bas et faites **Modifier...** :

<br/>

<p align="center">
	<img src="https://i.imgur.com/dM1AJX3.png" width="500">
</p>

<br/>

<br/>

Enfin, ajoutez le chemin copié plus tôt suivi de **\bin** dans la liste :

<br/>

<p align="center">
	<img src="https://i.imgur.com/mI4alUv.png" width="500">
</p>

<br/>

<br/>

Et voilà ! Il vous faut maintenant **MinGW**, si vous ne l'avez pas, vous trouverez comment faire ici :

* [Mode d'emploi pour installer **MinGW**.](#installer-mingw)

<br/>
