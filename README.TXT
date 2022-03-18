Citire input- 	am ales sa citesc input-ul folosind functia:
		-fgets pentru a citi fiecare linie;
		-strcspn ca sa elinim enter-ul de la final;
		-atoi ca sa iau valoare numerica a unor "string-uri";
		-strtok ca sa impart fiecare linie in string-uri.
main ():
	-am introdus matricea si am citit prima linie din input, pe care
	am folosit-o intr-un switch ca sa apelez functiile corespunzatoare
	task-urilor.
	-pentru task-urile 2 si 3 a folosit pointeri ca sa extrag datele din ele;
	am facut asta pentru ca am incercat sa folosesc task-ul 3 in task-ul 5,
	dar nu am reusit.

task-ul 1:
	-am citit numarul de cuvinte care trebuie puse pe board.
	-pentru fiecare cuvant am citit din linia corespunzatoare
	din input datele despre el(coordonate si directie), pe care
	le-am stocat in niste variabile numerice si pe el insusi l-am
	-copiat intr-un string separat(strcpy) pentru a lucra mai usor cu el.
	-apoi am determinat lungimea cuvantului ca sa pot pune pe tabla fiecare
	litera din componenta sa, in functie de directie.
	-am oprit while-ul atunci cand am parcurs toate liniile din input
	folosindu-ma de un if si o variabila stop.

task-ul 2:
	-am stocat doar cuvantul fiecarui jucator, fiindca nu am nevoie de alte date.
	-apoi am coparat fiecare litera din el cu literele care au un anumit punctaj
	si am atribuit acel punctaj unei variabile, pe care o adaug la scorul 
	jucatorilor de fiecare data cand while-ul este parcurs.
	-pentru a imi da seama carui jucator sa ii atribui punctajul am considerat
	liniile pare(stop % 2 == 0) ca fiind cuvintele puse de primul jucator si cele
	impare cuvintele puse de al doilea jucator.
	-la final am schimbat valoarea stocata in adresele date ca input ca sa le pot
	folosi updatate in switch si sa pot sa afisez output-ul final.

task-ul 3:
	-fac totul intr-un while in care prima parte este asemanatoare cu task-ul 2,
	numai ca acum stochez si datele despre cuvinte.
	-folosind substringurile citite la inceput determin daca sunt indeplinte
	conditiile de bonus pentru fiecare cuvant in parte.
	-BONUSUL 1: daca un cuvant are in componenta sa primul substring citit
		    (setez un flag care indica asta)si daca, pe tabla de bonusuri 
		    acesta trece peste un 1(iar setez un flag),
		    caz in care dublez punctajul jucatorului pentru acel cuvant.
	-BONUSUL 2: daca un cuvant are la final cele doua litere din al doilea
		    substring si trece in tabla de bonusuri peste un 2
		    triplez punctajul.
	-pentru fiecare cuvant resetez flag-urile.
	-in timp ce calculez punctajele le si stochez intr-un vector 
	care pe pozitiile pare are puntajele pentru primul jucator si
	pe pozitiile impare cele pentru al doilea jucator.
	-am adunat toate punctajele jucatorilor in doua variabile cu ale caror valori
	am modificat ce era scris inainte in adresele pe care le-am primit ca input.

task-ul 4:
	 -prima data am citit si stocat toate datele despre cuvinte in vectori,
	pentru a le putea accesa pentru fiecare cuvant in parte.
	-apoi am scris pe tabla cuvintele date ca input.
	-pentru a verifica daca un cuvant poate sa fie pus pe tabla
	m-am folosit de flag-uri.
	-ca sa pun pe tabla primul cuvant din lista ca indeplineste conditiile,
	am inceput while-ul cu un for care parcurge aceasta lista si se opreste
	atunci cand un cuvant este pus pe tabla(fapt indicat de un flag)
	-pentru  fiecare cuvant verific daca acesta este sau nu pe tabla,
	parcurgand fiecare cuvant din input stocat anterior intr-un vector de
	string-uri cu functia strcmp; daca cuvantul se afla deja pe tabla
	se trece la urmatorul cuvant.
	-in continuare, parcurg toata tabla cu doua for-uri si:
	  -verific daca prima litera din cuvant se regaseste pe tabla, apoi
	  -verific daca acesta incape pe tabla de joc adunandu-i lungimea cu
	   coordonata unde urmeaza sa fie pus(in functie de directie), 
	   scazand-o cu 1, deoarece prima litera este deja pusa si comparand-o
	   in final cu 15(acesta fiind lungimea/latimea maxima)
	   -daca trece si de aceasta conditie, verific daca locul unde urmeaza
	   sa fie pus cuvantul intersecteaza o litera.
	-daca toate flag-urile setate pentru conditiile de mai sus(fie pentru
	pozitionarea cuvantului pe verticala sau orizontala) sunt adevarate
	pun cuvantul pe tabla si setez un flag care sa produca iesirea din while.
	-pentru fiecare cuvant resetez flag-urile.
	-la final printez tabla.

task-ul 5:
	-in prima parte a functiei stochez datele in vectori si cu ajutorul lor
	pun cuvintele din input pe tabla si calculez scorul fiecarui jucator.
	-pentru a determina care cuvant imi poate aduce castigul sau egalul,
	verific mai intai ce cuvinte pot fi puse pe fiecare pozitii, incepand
	cu 0 0(astfel va fi ales cuvantul care are punctajul cel mai mare si
	poate fi pus pe cea mai mica linie si coloana).
	-fata de task-ul 4, dupa ce am verificat daca un cuvant poate fi pus 
	pe tabla calzulez punctajul pe care acesta il produce atunci cand e
	jucat(pe verticala sau orizontala) si il compar cu o variabila max
	care isi schimba valoarea numai daca un alt cuvant produce un puntaj
	strict mai mare, caz in care ii copiez si datele.
	-daca exista mai multe cuvinte care produc acelasi puntaj, si acela 
	este punctajul maxim variabila max nu se va schimba, ramanand astfel
	stocate doar datele cuvantului ce poate fi pus pe cea mai mica linie
	sau coloana.
	-la final, in functie de directia pe care poate sa fie pus cuvantul
	il printez pe tabla, insa folosesc if si else if ca sa priritizez
	pozitionarea lui pe orizontala, asa cum se cere in enunt.
   funtia punctaj_cuvant:
	-calculeaza punctajul produs de un cuvant dat la fel ca task3,
	numai ca pentru un singur cuvant si avand datele despre
	substring-uri, coordonate si directie deja date.