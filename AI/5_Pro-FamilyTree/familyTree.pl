/* Facts */
male(sanil).
male(nikhil).
male(ravindra).
male(rugved).
male(vedant).
male(kiran).
female(sarika).
female(pallavi).
female(manjari).

parent_of(nikhil,sanil).
parent_of(sarika,sanil).
parent_of(ravindra, nikhil).
parent_of(pallavi, nikhil).
parent_of(kiran,rugved).
parent_of(manjari, rugved).
parent_of(kiran, vedant).
parent_of(manjari, vedant).
parent_of(ravindra, manjari).
parent_of(pallavi, manjari).

/* Rules */
father_of(X,Y):- male(X),
    parent_of(X,Y).

mother_of(X,Y):- female(X),
    parent_of(X,Y).

grandfather_of(X,Y):- male(X),
    parent_of(X,Z),
    parent_of(Z,Y).

grandmother_of(X,Y):- female(X),
    parent_of(X,Z),
    parent_of(Z,Y).

sister_of(X,Y):- %(X,Y or Y,X)%
    female(X),
    father_of(Father, Y), father_of(Father,X),X \= Y.

sister_of(X,Y):- female(X),
    mother_of(Mother, Y), mother_of(Mother,X),X \= Y.

aunt_of(X,Y):- female(X),
    parent_of(Z,Y), sister_of(X,Z),X \= Y.

brother_of(X,Y):- %(X,Y or Y,X)%
    male(X),
    father_of(F, Y), father_of(F,X),X \= Y.

brother_of(X,Y):- male(X),
    mother_of(M, Y), mother_of(M,X),X \= Y.

uncle_of(X,Y):-
    parent_of(Z,Y), brother_of(Z,X).

ancestor_of(X,Y):- parent_of(X,Y).
ancestor_of(X,Y):- parent_of(X,Z),
    ancestor_of(Z,Y).

husband_of(X,Y) :- male(X),
    father_of(X,Child), mother_of(Y,Child).

