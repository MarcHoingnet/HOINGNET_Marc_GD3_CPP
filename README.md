# HOINGNET_Marc_GD3_CPP
## Introduction :

Le projet s’articule autour de la base du jeu de plateau vu en cours.
Mon but était de l’améliorer et de le rendre fun le plus possible.
Manquant cruellement de connexion pour rajouter des assets sur le projet, j’ai dû me limiter aux formes Unreal de base, j’ai donc augmenté mes efforts sur les widgets, le level design pur, ainsi que le sound design, dans le but d’avoir un prototype agréable.

## Jeu de plateau – POC :
Le jeu de plateau prend place dans une grande métropole avec un taux de criminalité élevé. Ici, vous incarnez, tour à tour, deux livreurs cleptomanes qui doivent voler le plus de chose (points) pour les apporter à leur repère ! Le premier arrivé a gagné !
Pour cela, ils devront avancer en passant par des lieux (cases) spéciaux qui proposera au joueur des mini-jeux :
-	*Le Memory* : même principe qu’avec des cartes mais avec les fenêtres d’un bâtiment
-	*Le Runner* : entrer dans un bâtiment et récupérer le plus d’objets (points) en évitant ce qui pourra vous faire repérer (malus) en un temps imparti.

### Concret :
Pour ce travail, j’ai décidé d’allonger et de reformer le plateau de jeu avec ses cases.
J’y ai rajouté beaucoup de feedbacks, autant visuel que sonore (animations de widget, SFX, textes, etc…), pour que l’expérience du joueur soit plus appréciable et la plus fluide possible pour ce prototype.
Pour les cases mini-jeux, j’ai opté pour un changement de référence du *level* concerné, directement dans le details du BP une fois qu’il est positionné sur le *level*.
Cela évite de faire un nouveau BP par mini-jeu, c’est aussi plus optimisé et plus rapide si dans le futur d’autre mini-jeux doivent être rajouté.

En donnant de l’importance au sound design dans mon projet, j’ai décidé de développé un menu d’option d’sonore.
Je l’ai fait fonctionner avec des sons qui ont renseigné en eux un *Sound Class* dédié (music ou sfx).
Ces Sound Class sont gérés par une *Sound Class Mix* et leur valeurs liés à des sliders dans le *widget* respectif.

A cela j’ai rajouté tout un système permettant de sauvegarder les modifications liées au volume général, des musiques et des bruitages avec un *Save Game Object*.
J’ai aussi créer un menu pause, auquel le joueur peut accéder en appuyant soit sur Escape (et P dans l’editor Unreal), soit en appuyant sur le bouton en bas à gauche du plateau.
Ce bouton va mettre le jeu en pause et proposer au joueur de revenir à l’écran de titre, tout en sauvegardant l’avancée de la partie grâce au *Game Instance*.

J'ai aussi essayé de donner une certaine DA au jeu, pour cela j'ai utilisé l'IA et grâce à mes prompts, j'ai pu reste dans un style cartoon simple et amusant.
Même chose pour les musiques et les bruitages, le but étant de tout lier entre-eux pour avoir une cohérence autant sonore que visuelle.

Pour le mini jeu du Collectible, j'ai travaillé le Level Design de tel sorte que le joueur découvrira des nouveaux chemins et des nouvelles manières d'optimiser son run pour les prochaines fois.
J'ai aussi voulu jouer avec la hauteur et les points de vue, pour rajouter une partie stratégique au jeu de plateau. Le joueur pourra utiliser sa première run sur le mini-jeu pour se repérer,
ou bien pour tenter d'avoir directement le plus de points, quite a tomber dans certains pieges. Ici, le but est de proposer au joueur une expérience bien plus active et stressante où il
devra faire preuve de réflexion en un temps imparti. Cela permet en plus de jouer avec le flow du jeu ainsi qu'avec les émotions du joueur.


## Jeu de plateau - Collectible CPP :
