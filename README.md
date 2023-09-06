# Navy
A battle ship game

Ce programme est une version terminale du très célèbre jeu la battaille navalle utilisant les signaux.  
Les deux joueurs communiquent UNIQUEMENT en utilisant les signaux SIGUSER1 et SIGUSER2.

La taille de la carte est de 8x8. A chaque tour, le programme affiche la positions du joueur, puis les positions de l'ennemi.  
A la fin de la partie (quand tous les vaisseaux d'un joueur ont été touché), le programme affiche soit « J'ai gagné » (et renvoyer 0) ou « L'ennemi a gagné » (et renvoie 1).
<p align="center">
  <img src="https://github.com/RainproDash/Navy/assets/91848714/b99d8ae9-dcbf-4105-8394-b1fe1f7b83a8" alt="Image de démonstration">
</p>


Le fichier passé en paramètre doit contenir des lignes formatées de la manière suivante :  
LONGUEUR : PREMIER_CARRÉ : DERNIER_SQUARE  
Où LONGUEUR est la longueur du navire, PREMIER_CARRÉ et DERNIER_SQUARE ses première et dernière positions.  
Dans ce fichier, doit disposer de 4 vaisseaux (de longueurs 2,3,4 et 5).  
Si le fichier n'est pas valide, programme considére ça comme une erreur.

Voici des exemples de fichiers

![image](https://github.com/RainproDash/Navy/assets/91848714/e6d32033-546e-4d49-9e57-dbe348a053aa)   ![image](https://github.com/RainproDash/Navy/assets/91848714/cea70e10-37fc-4985-b464-02784d684207)

Pour la connection entre les deux joueurs

Joueur 1 :

![image](https://github.com/RainproDash/Navy/assets/91848714/33a77f4b-bd06-4f6a-bc72-3b2e970ca28b)

Joueur 2 :

![image](https://github.com/RainproDash/Navy/assets/91848714/7fd35a69-cedc-47e6-abd7-fcf0eac15626)

Et enfin le déroulement du jeu :

Tour 1

Joueur 1

![image](https://github.com/RainproDash/Navy/assets/91848714/82eb6b55-1a7f-489c-814f-9331b816ff94)

Joueur 2

![image](https://github.com/RainproDash/Navy/assets/91848714/2615e8f5-12c5-4ec4-8b80-8aa03d5c6503)

Tour 2 

Joueur 1

![image](https://github.com/RainproDash/Navy/assets/91848714/9d178995-f8df-4bc8-b49f-01f98c03153f)

Joueur 2

![image](https://github.com/RainproDash/Navy/assets/91848714/1a702e67-0bca-4e52-9a16-e3b5ca28d828)

Dernier tour

Joueur 1

![image](https://github.com/RainproDash/Navy/assets/91848714/977d5e2d-f4b3-4aba-8634-9973ec4dedb6)

Joueur 2

![image](https://github.com/RainproDash/Navy/assets/91848714/e3c6bed8-e13d-42c3-b465-01eddea0c152)
