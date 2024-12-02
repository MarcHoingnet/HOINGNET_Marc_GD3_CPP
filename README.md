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

Pour le mini jeu du Collectible, j'ai travaillé le Level Design de tel sorte que le joueur découvrira des nouveaux chemins et des nouvelles manières d'optimiser son run pour les prochaines fois, plein de choix sont possible.
J'ai aussi voulu jouer avec la hauteur et les points de vue, pour rajouter une partie stratégique au jeu de plateau. Le joueur pourra utiliser sa première run sur le mini-jeu pour se repérer,
ou bien pour tenter d'avoir directement le plus de points, quite a tomber dans certains pieges. Ici, le but est de proposer au joueur une expérience bien plus active et stressante où il
devra faire preuve de réflexion en un temps imparti. Cela permet en plus de jouer avec le flow du jeu ainsi qu'avec les émotions du joueur.

Pour le mini jeu du Memory, le joueur fera face à 8 fenetres qu'il devra ouvrir pour en découvrir le contenu. Le joueur gagne 2 points par paire trouvée, ces points seront directement ajouté a son score.
Comme pour le Collectible, a la fin du mini-jeu apparaitra un *Widget* qui nous demande de retourner au plateau principale, pour continuer le jeu où il s'était arrêter, en reprenant la sauvegarde grâce au *Game Instance*.


## Jeu de plateau - Collectible CPP :
Pour la partie C++ du mini-jeu Collectible, j'ai commencé par créer une *Class object* et une *Class Game Mode*
Tout d'abord l'object Collectible sert à définir les 2 types de collectibles présent dans le jeu (Bonus & Malus)
j'ai crée une *Boolean* qui me permet de savoir si un collectible est un bonus ou un malus, pour ensuite le Destroy lorsque le joueur rentre en collision avec, 
et ainsi obtenir les points attribué (+10 ou -10).

Ensuite, j'ai crée un Game Mode dédié au collectible en C++
Il va me permettre :
- d'afficher le *Widget* de mon score 
- de mettre a jour mon score total
- d'avoir un timer fonctionnel et modifiable
- de fait apparaitre un *Widget* de fin du mini-jeu une fois le timer écoulé

J'ai décidé de faire tout le reste en Blueprint car ce n'était pas des choses qui demandaient beaucoup de ressources ou encore une forte optimisation
- les widgets secondaires liés au collectible
- les BP Bonus et Malus lié néanmoins a la partie C++
- le Level Blueprint pour la sauvegarde des parametres sonores
- et pour le lancement du timer (grâce a la fonction en C++)

Le but ici était d'optimiser le plus possible ces fonctions grâce au C++
- Performance accrue avec le gain de Performance que propose le C++ directement compilé en instructions machine, et moins de surcharge que le blueprint
- Plus de controle et de flexibilité avec le C++ qui a un accès de bas niveau et qui offre plus de possibilité que le Blueprint.
- Debuging plus précis avec Rider et/ou Visual Studio et leur messages d'erreur souvent plus précis
- Meme si ce n'est pas encore le cas, si ce projet vient un jour a se considérer comme un gros projet ambitieux, l'utilisation de C++ sera plus adapté
- Le C++ permet d'utiliser des bibliothèques tierces ou d'intégrer d'autres systèmes externes plus facilement.
- On peut aussi interfacer Unreal Engine avec des frameworks ou outils qui ne sont pas compatibles avec Blueprints.

Le blueprint cependant est préférable dans plusieurs cas :
- Prototypage rapide : Les Blueprints sont parfaits pour tester des concepts rapidement comme toute les petites mécaniques de ce jeu.
- Projets simples : Pour des jeux ou projets peu complexes, ils suffisent largement.
- Accessibilité : Les Blueprints sont plus intuitifs, surtout pour les personnes comme moi qui ont encore beaucoup de mal avec le code.

Il est important de noter que les 2 marche tres bien ensemble si tout est bien fait, ils deviennent vite complémentaires.

A noter que ce Game Mode va être réutilisé en *Blueprint* pour pouvoir lié le score total du Collectible au score final du joueur sur le board
et pour récupérer les fonctions lié au timer par exemple et les reutiliser.
