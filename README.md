# Guide pour le projet So Long

## Introduction
**So Long** est un projet de l'école 42 qui consiste à développer un jeu en 2D en utilisant la bibliothèque **MiniLibX**. L'objectif est de guider un personnage à travers une carte, en collectant des objets tout en atteignant une sortie. Ce projet permet de renforcer vos compétences en programmation C, en gestion de la mémoire et en développement de jeux vidéo simples.

---

## Prérequis
Avant de commencer, assurez-vous d'avoir les éléments suivants :

- **MiniLibX** installée (incluse dans le repository de l'école 42).
- Un système Unix/Linux ou macOS.
- GCC ou tout autre compilateur C compatible.
- Un fichier carte respectant le format requis (extension `.ber`).

---

## Installation

1. Assurez-vous que tous les fichiers nécessaires sont présents dans le dossier du projet.

2. Compilez le projet avec **Makefile** :
   ```bash
   make
   ```

3. Lancez le jeu en fournissant le chemin vers un fichier de carte valide :
   ```bash
   ./so_long maps/map.ber
   ```

---

## Structure du projet

- **`Makefile`** : Automatise la compilation du projet.
- **`main.c`** : Point d'entrée principal du programme.
- **`character_move.c`** : Gère les déplacements du personnage.
- **`collectible_capture.c`** : Gère la collecte des objets.
- **`display.c`** : Gère l’affichage graphique.
- **`key_press.c`** : Gère les entrées clavier.
- **`free.c`** : Libère la mémoire utilisée.
- **`error_*.c`** : Gère différents types d’erreurs (carte, doublons, etc.).

---

## Guide détaillé pour réaliser le projet

### 1. Lecture et validation de la carte

La carte est lue à partir d'un fichier **`.ber`**. Voici les règles à respecter :

- La carte doit être rectangulaire.
- Les bords de la carte doivent être fermés par des murs (`1`).
- La carte doit contenir au moins :
  - Un joueur (`P`).
  - Une sortie (`E`).
  - Un collectable (`C`).

**Exemple de carte valide** :
```
11111
1P0C1
1E001
11111
```

Pour lire et valider la carte, vous pouvez implémenter une fonction similaire à celle-ci :
```c
void initialize_map(const char *file_name) {
    int fd = open(file_name, O_RDONLY);
    if (fd < 0) {
        perror("Erreur d'ouverture de la carte");
        exit(EXIT_FAILURE);
    }
    parse_map(fd);
    close(fd);
}
```

### 2. Gestion des déplacements du personnage

Le joueur peut se déplacer avec les touches suivantes :

- **W** : Haut
- **A** : Gauche
- **S** : Bas
- **D** : Droite

Les déplacements doivent respecter les règles suivantes :

- Ne pas traverser les murs (`1`).
- Ramasser les collectables (`C`) en passant dessus.
- Atteindre la sortie (`E`) uniquement après avoir collecté tous les objets.

**Code exemple pour gérer les déplacements** :
```c
void move_player(t_game *game, int dx, int dy) {
    int new_x = game->player.x + dx;
    int new_y = game->player.y + dy;
    char next_pos = game->map[new_y][new_x];

    if (next_pos == '1') return; // Collision avec un mur

    if (next_pos == 'C') {
        game->collectibles--;
        game->map[new_y][new_x] = '0'; // Retire le collectable de la carte
    }

    game->map[game->player.y][game->player.x] = '0'; // Efface l'ancienne position
    game->player.x = new_x;
    game->player.y = new_y;
    game->map[new_y][new_x] = 'P'; // Met à jour la nouvelle position
}
```

### 3. Gestion de la sortie

Une fois que tous les collectables sont ramassés, le joueur peut atteindre la sortie. Voici un exemple de vérification :
```c
void check_exit(t_game *game) {
    if (game->collectibles == 0 && game->map[game->player.y][game->player.x] == 'E') {
        printf("Félicitations ! Vous avez terminé le niveau !\n");
        exit(EXIT_SUCCESS);
    }
}
```
