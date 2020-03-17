# initiationCPP
Exercices pour illustrer l'apprentissage de C++

1)	Présentation

On veut surveiller ou piloter un environnement (par exemple une maison ou un appareil) à partir de mesures réalisées par des capteurs (par exemple capteur de température, de pression, de position, de tension, …).  
On prévoit de définir un environnement à l’aide d’un bloc comportant un ou plusieurs capteurs.

2)	Première étape : prototype d’un capteur de température

Le capteur est décrit par :
-	Un nom ; composé d’au moins trois caractères. On fait le choix d’utiliser un pointeur vers une string.
-	Un code num pour identifier physiquement le thermomètre
-	Une plage de fonctionnement normal définie par min et max
-	Une valeur logique qui indique s’il faut contrôler ou non la plage de fonctionnement

On veut pouvoir initialiser le capteur :
-	En spécifiant uniquement le nom et le code, il n’y aura pas de contrôle de plage de validité
-	En spécifiant le nom, le code et la valeur min et la valeur max

a)	Ecrire une première version des constructeurs pour initialiser le capteur.  
Quelle précaution doit-on prendre ? 

Pour contrôler le capteur, on dispose d’une fonction C  : int thermometre(num, code).
-   code = 0 permet d’acquérir le capteur et de l’initialiser
-   code = 1 permet de libérer le capteur
-   code = 2 fournit une valeur de température  
En cas d’erreur, la valeur de retour est négative.

b)	Ecrire une nouvelle version des constructeurs pour prendre en compte ces initialisations.

On veut pouvoir obtenir la température avec la méthode float getValeur(), savoir si on dans la plage avec la méthode bool estValide().  
Les erreurs d’acquisition sont signalées par une exception.  
c)	Ecrire les méthodes getValeur et estValide().

On veut pouvoir comparer deux capteurs de température.  
d)	Ecrire la surcharge de operator==.  
Est-ce qu’il ne faudrait pas écrire quelque chose d’autre pour éviter un problème ?

On veut pouvoir « imprimer » dans un flux un capteur, en obtenant le nom, le code et min, max si elles sont activées.  
e)	Ecrire la surcharge de operator<<.  
Quelles solutions sont possibles si les champs de nom, code, min et max sont privés ?

On veut pouvoir savoir si on est en dessous de la valeur min, dans la plage ou au dessus de la valeur max.  
f)	Que proposez-vous comme valeur de retour de estValide() ? Implantez cette nouvelle écriture

On veut que plusieurs capteurs puissent avoir les mêmes valeurs min et max, et pouvoir changer ces valeurs immédiatement pour ce groupe de capteurs.  
g)	Que proposez-vous comme solution ? Implantez cette nouvelle écriture

h)	Est-ce que vous avez pensé à vérifier la règle des trois pour cette classe ? Si non, corrigez la classe.

i)	On veut savoir combien d’instance de la classe capteurTemperature ont été créé.  
Implémenter cette fonctionnalité.

3)	Deuxième étape : famille de capteur

On souhaite maintenant gérer également des capteurs de pression, de position, …  
On constate que tous ces capteurs ont comme points communs :
-	Un nom
-	Un code
-	Une méthode pour obtenir une valeur

j)	Ecrire une classe de base pour implémenter ces membres et faire dériver capteurTemperature de cette classe de base.

k)	Ecrire une classe capteurPression, sans implémenter de contrôle de plage de validité.

4)	Troisième étape : création de blocs

On souhaite maintenant pouvoir définir des assemblages de capteurs pour contrôler différents éléments, par exemple dans une maison, un appareil électrique, …  
Un bloc comporte les éléments suivants :
-	Un nom
-	Une liste de capteur

On veut pouvoir ajouter ou supprimer des capteurs, connaitre le nombre de capteurs présents, afficher la liste des capteurs.  
l)	Quels sont les possibilités pour implémenter la liste des capteurs ? 

m)	Implémenter la classe bloc en choisissant une possibilité évoquée.  
NB : certaines possibilités sont plus complexes à implanter que d’autres…

5)	Quatrième étape : perfectionnements

On s’aperçoit qu’utiliser les exceptions standards peut conduire à des confusions.  
n)	Créez votre propre hiérarchie d’exception et implémenter la.

On s’aperçoit que la valeur de retour d’une mesure peut avoir des types différents, qu’il peut être nécessaire d’indiquer une unité, une précision de mesure, un instant de mesure, ….  
o)	Quels sont les possibilités pour prendre en compte ces contraintes sans écrire plusieurs fois des classes quasi identiques  ?  
Implémentez une solution dans la classe capteur. 


