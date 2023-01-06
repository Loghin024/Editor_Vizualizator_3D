#include <direct.h>
#include "foldersAndTexts.hpp"
#include <iostream>

void createFolderAndTexts()
{
	if (_mkdir("src\\userProjects"));
	FILE* createProjectsText = fopen("src\\userProjects/userNameOfProjects.txt", "a");
	fclose(createProjectsText);

	if (_mkdir("src\\programtexts"));
	FILE* programUtilities1 = fopen("src\\programtexts/textsForPrincipalScreen.txt", "w");
	fprintf(programUtilities1, "%s", "Editor/Vizualizator 3D\nEDITING / VISUALISATION 3D\nRusa\nRO\nEN\nRU\nProiectele mele\nMy projects\nRusa\nCreeza proiect\nCreate Project\nrusa");
	fclose(programUtilities1);


	FILE* programUtilities2 = fopen("src\\programtexts/textsForViewerScreen.txt", "w");
	fprintf(programUtilities2, "%s", "Proiectele mele:\nMy projects :\nrusa:\nInapoi\nBack\nrusa\nProiect nou\nNew project\nrusa\nSterge\nDelete\nRusa\nVizionare\nView\nrusa");
	fclose(programUtilities2);

	FILE* programUtilities3 = fopen("src\\programtexts/textsForCreateScreenCub.txt", "w");
	fprintf(programUtilities3, "%s", "inapoi\nback\nrusa\n");
	fprintf(programUtilities3, "%s", "Introduceti coordonatele lui\nPut the Coordonates of\nRusa\nInaltime:\nHeight:\nRusa\nNumele figurii:\nThe name of figure:\nrusa\nDiametru\nDiameter\nrusa");
	fclose(programUtilities3);

	FILE* programUtilities7 = fopen("src\\programtexts/textsForCreateScreenPrisma.txt", "w");
	fprintf(programUtilities7, "%s", "Numele figurii:\nThe name of figure:\nrusa\nIntroduceti coordonatele lui\nPut the Coordonates of\nRusa\nInaltime:\nHeight:\nRusa\nLatime:\nWidth:\nRusa\nLungime:\nLenght:\nRusa");
	fclose(programUtilities7);

	FILE* programUtilities4 = fopen("src\\programtexts/viewAndEdit.txt", "w");
	fprintf(programUtilities4, "%s", "Adaugati figura:\nAdd figure:\nRusa\nComponente:\nComponents:\nRusa:\nApasati enter pentru mod vizualizare\nPress enter for view mode\nRusa");
	fclose(programUtilities4);

	/*FILE* programUtilities5 = fopen("src\\programtexts/posibleFigures.txt", "w");
	fprintf(programUtilities5, "%s", "Cub\nPrisma\nLinie\nfigura4\nfigura 5\nfigura 6\nfigura 7\nfigura 8\nfigura 9");
	fclose(programUtilities5);*/

	FILE* programUtilities6 = fopen("src\\programtexts/giveNameForProject.txt", "w");
	fprintf(programUtilities6, "%s", "Dati numle proiectului:\nGive the name of project:\nrusa\nInapoi\nBack\nrusa");
	fclose(programUtilities6);

	FILE* programUtilities8 = fopen("src\\programtexts/textsForCreateScreenCon.txt", "w");
	fprintf(programUtilities8, "%s", "inapoi\nback\nrusa\n");
	fprintf(programUtilities8, "%s", "Introduceti coordonatele lui\nPut the Coordonates of\nRusa\nInaltime:\nHeight:\nRusa\nNumele figurii:\nThe name of figure:\nrusa\nRaza:\nRadius:\nrusa");
	fclose(programUtilities8);


	FILE* programUtilities9 = fopen("src\\programtexts/textsForCreateScreenPiramide.txt", "w");
	fprintf(programUtilities9, "%s", "Numele figurii:\nThe name of figure:\nrusa\nIntroduceti coordonatele lui\nPut the Coordonates of\nRusa\nInaltime:\nHeight:\nRusa\nLungime baza:\nBase length:\nRusa\nLatime baza:\nBase lenght:\nRusa");
	fclose(programUtilities9);

	FILE* programUtilities10 = fopen("src\\programtexts/textsForSizes.txt", "w");
	fprintf(programUtilities10, "%s", "Marime:\nSize:\nRusa\nLungime:\nLenght:\nRusa\nInaltime:\nHeight:\nRusa\nLatime:\nWidth:\nRusa\nDiametru:\nDiameter:\nRusa\nRaza:\nRadius:\nRusa");
	fclose(programUtilities10);

	if (_mkdir("src\\images"));
	if (_mkdir("src\\Fonts"));
}
