#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 3800000000
#define MASS_H 1.0079
#define MASS_O 15.9994
#define MASS_N 14.0067
#define MASS_C 12.0107

 
int eleIndex;
int genAtom(void);
double processAtom(int atomNum, int* CompoundCharge, int* pH, int* pO, int* pN, int* pC);
float getWeight(const int numC, const int numH, const int numO, const int numN);
int moleculeFound(float weight, int charge, int c, int h, int o, int n);
void printData(int index);
typedef struct
{
    char name[14];
    float weight;
    int h, o, n, c;
}AminoAcid;
AminoAcid list[] = {{"Alanine", 89.0929, 7, 2, 1, 3},
                            {"Aspartic acid", 133.1024, 7, 4, 1, 4},
                            {"Glutamic acid", 147.1289, 9, 4, 1, 5},
                            {"Phenylalanine", 165.1887, 11, 2, 1, 9},
                            {"Glycine", 75.0664, 5, 2, 1, 2},
                            {"Histidine", 155.1542, 9, 2, 3, 6},
                            {"Isoleucine", 131.1724, 13, 2, 1, 6},
                            {"Lysine", 146.1870, 14, 2, 2, 6},
                            {"Leucine", 131.1724, 13, 2, 1, 6},
                            {"Asparagine", 132.1176, 8, 3, 2, 4},
                            {"Proline", 115.1301, 9, 2, 1, 5},
                            {"Glutamine", 146.1441, 10, 3, 2, 5},
                            {"Arginine", 174.2004, 14, 2, 4, 6},
                            {"Serine", 105.0923, 7, 3, 1, 3},
                            {"Threonine", 119.1188, 9, 3, 1, 4},
                            {"Valine", 117.1459, 11, 2, 1, 5},
                            {"Tryptophan", 204.2247, 12, 2, 2, 11},
                            {"Tyrosine", 181.1881, 11, 3, 1, 9}};
 
int main()
{
    srand(time(NULL));
    int years = 0;
    int eleCharge = 0, eleH = 0, eleO = 0, eleN = 0, eleC = 0, i;
    float eleWeight;
    //printf("%s %.2f %d %d %d %d", list[0].name, list[0].weight, list[0].h, list[0].o, list[0].n, list[0].c);
    //getchar();
    //printf("%u", years);
    do
    {
         
        if (eleWeight = processAtom(genAtom(), &eleCharge, &eleH, &eleO, &eleN, &eleC)){
            for (i = 0; i < sizeof(list) / sizeof(list[0]); i++)
            {
                if (list[i].weight == eleWeight)
                    eleIndex = i;
            }
			{
            printf("The amino Acid: %s Has been found!\n", list[eleIndex].name);
            printf("%d years has passed.\n", years);
            printData(eleIndex);
            getchar();
            return 0;
            do ( years++);
            
    }  
	  { else
	        while (years < MAX_YEAR);
            printf("Earth is a Lifeless Plant");
            return 0;
            getchar();
     
}
float getWeight(const int numC, const int numH, const int numO, const int numN){
    return numC * MASS_C + numH * MASS_H + numO * MASS_O + numN * MASS_N;
}
int genAtom(void){
    return 1 + rand() % 4;
}
double processAtom(int atomNum, int *CompoundCharge, int *pH, int *pO, int *pN, int *pC){
    float weight;
    switch (atomNum)
    {
    case 1: 
        *pH += 1;
        *CompoundCharge += 1;
        break;
    case 2:
        *pO += 1;
        if (*CompoundCharge > 0)
            *CompoundCharge -= 2;
        break;
    case 3:
        *pN += 1;
        if (*CompoundCharge > 0)
            *CompoundCharge -= 3;
        else if(*CompoundCharge < 0)
            *CompoundCharge -= 1;
        break;
    case 4:
        *pC += 1;
        if (*pC % 3 == 0){
            if (*CompoundCharge > 0)
                *CompoundCharge -= 2;
        }
        else
        {
            if (*CompoundCharge > 0)
                *CompoundCharge -= 4;
            else if (*CompoundCharge < 0)
                *CompoundCharge -= 2;
        }
        break;
    }
    
	
	if (*CompoundCharge < -4)   {*CompoundCharge += 3; *pH += 3;}
    weight = getWeight(*pC, *pH, *pO, *pN);
    if (weight > 204.2247) {*CompoundCharge = 0; *pH = 0; *pO = 0; *pN = 0; *pC = 0;}
    if (*CompoundCharge == 0 && moleculeFound(weight, *CompoundCharge, *pC, *pH, *pO, *pN))
        return weight;
    return 0;
}
int moleculeFound(float weight, int charge, int c, int h, int o, int n){
    int i, length = sizeof(list) / sizeof(list[0]); //18
    for (i = 0; i < length; i++)
    {
        if (list[i].weight == weight && list[i].c == c && list[i].h == h && list[i].o == o && list[i].n == n)
            return 1;
    }
	{
    return 0;
}
void printData(int index){
    printf("%-20s %-20s %-20s\n", "Name of Amino Acid Located:","Chemical Formula of Amino Acid:","Total Weight of Amino Acid:");
    printf("%-20s",list[index].name);
    if (list[index].n = 0)
        printf("%s%dH%dNO%d%20s%20.4f" ,list[index].c, list[index].h, list[index].o, "", list[index].weight);
    else
        printf("%s%dH%dNO%d%20s%20.4f", list[index].c, list[index].h,list[index].o , list[index].weight, list[index].n);
    printf("\n");
}
/*
Cat of Program Above and cc with product of program bellow:
Element: Valine Found!
337 years has passed.
Name                 Formula              Weight
Valine              C                   5H11N0O2            117.1459
a.out
nbulajic@matrix:~> a.out
Element: Serine Found!
2176 years has passed.
Name                 Formula              Weight
Serine              C                   3H7N0O3            105.0923

nbulajic@matrix:~> a.out
Element: Glycine Found!
2516 years has passed.
Name                 Formula              Weight
Glycine             C                   2H5N0O2             75.0664

nbulajic@matrix:~> a.out
Element: Serine Found!
1494 years has passed.
Name                 Formula              Weight
Serine              C                   3H7N0O3            105.0923

nbulajic@matrix:~> a.out
Element: Alanine Found!
456 years has passed.
Name                 Formula              Weight
Alanine             C                   3H7N0O2             89.0929

nbulajic@matrix:~> a.out
Element: Serine Found!
3140 years has passed.
Name                 Formula              Weight
Serine              C                   3H7N0O3            105.0923

nbulajic@matrix:~> a.out
Element: Lysine Found!
3668 years has passed.
Name                 Formula              Weight
Lysine              C                   6H14N0O2            146.1870
a
nbulajic@matrix:~> a.out
Element: Serine Found!
3327 years has passed.
Name                 Formula              Weight
Serine              C                   3H7N0O3            105.0923

nbulajic@matrix:~> a.out
Element: Serine Found!
1367 years has passed.
Name                 Formula              Weight
Serine              C                   3H7N0O3            105.0923

nbulajic@matrix:~> a.out
Element: Glycine Found!
4531 years has passed.
Name                 Formula              Weight
Glycine             C                   2H5N0O2             75.0664

nbulajic@matrix:~> a.out
Element: Serine Found!
2611 years has passed.
Name                 Formula              Weight
Serine              C                   3H7N0O3            105.0923

nbulajic@matrix:~> a.out
Element: Glycine Found!
1646 years has passed.
Name                 Formula              Weight
Glycine             C                   2H5N0O2             75.0664

nbulajic@matrix:~> a.out
Element: Glutamine Found!
944 years has passed.
Name                 Formula              Weight
Glutamine           C                   5H10N0O3            146.1441

nbulajic@matrix:~> a.out
Element: Asparagine Found!
105 years has passed.
Name                 Formula              Weight
Asparagine          C                   4H8N0O3            132.1176

nbulajic@matrix:~> a.out
Element: Threonine Found!
3251 years has passed.
Name                 Formula              Weight
Threonine           C                   4H9N0O3            119.1188

nbulajic@matrix:~> a.out
Element: Glycine Found!
1438 years has passed.
Name                 Formula              Weight
Glycine             C                   2H5N0O2             75.0664

nbulajic@matrix:~> a.out
Element: Threonine Found!
1012 years has passed.
Name                 Formula              Weight
Threonine           C                   4H9N0O3            119.1188
a.out
nbulajic@matrix:~> a.out
Element: Aspartic acid Found!
237 years has passed.
Name                 Formula              Weight
Aspartic acid       C                   4H7N0O4            133.1024

Element: Valine Found!
337 years has passed.
Name                 Formula              Weight
Valine              C                   5H11N0O2            117.1459
a.out
nbulajic@matrix:~> a.out
Element: Serine Found!
2176 years has passed.
Name                 Formula              Weight
Serine              C                   3H7N0O3            105.0923

nbulajic@matrix:~> a.out
Element: Glycine Found!
2516 years has passed.
Name                 Formula              Weight
Glycine             C                   2H5N0O2             75.0664

nbulajic@matrix:~> a.out
Element: Serine Found!
1494 years has passed.
Name                 Formula              Weight
Serine              C                   3H7N0O3            105.0923

nbulajic@matrix:~> a.out
Element: Alanine Found!
456 years has passed.
Name                 Formula              Weight
Alanine             C                   3H7N0O2             89.0929

nbulajic@matrix:~> a.out
Element: Serine Found!
3140 years has passed.
Name                 Formula              Weight
Serine              C                   3H7N0O3            105.0923

nbulajic@matrix:~> a.out
Element: Lysine Found!
3668 years has passed.
Name                 Formula              Weight
Lysine              C                   6H14N0O2            146.1870
a
nbulajic@matrix:~> a.out
Element: Serine Found!
3327 years has passed.
Name                 Formula              Weight
Serine              C                   3H7N0O3            105.0923

nbulajic@matrix:~> a.out
Element: Serine Found!
1367 years has passed.
Name                 Formula              Weight
Serine              C                   3H7N0O3            105.0923

nbulajic@matrix:~> a.out
Element: Glycine Found!
4531 years has passed.
Name                 Formula              Weight
Glycine             C                   2H5N0O2             75.0664

nbulajic@matrix:~> a.out
Element: Serine Found!
2611 years has passed.
Name                 Formula              Weight
Serine              C                   3H7N0O3            105.0923

nbulajic@matrix:~> a.out
Element: Glycine Found!
1646 years has passed.
Name                 Formula              Weight
Glycine             C                   2H5N0O2             75.0664

nbulajic@matrix:~> a.out
Element: Glutamine Found!
944 years has passed.
Name                 Formula              Weight
Glutamine           C                   5H10N0O3            146.1441

nbulajic@matrix:~> a.out
Element: Asparagine Found!
105 years has passed.
Name                 Formula              Weight
Asparagine          C                   4H8N0O3            132.1176

nbulajic@matrix:~> a.out
Element: Threonine Found!
3251 years has passed.
Name                 Formula              Weight
Threonine           C                   4H9N0O3            119.1188

nbulajic@matrix:~> a.out
Element: Glycine Found!
1438 years has passed.
Name                 Formula              Weight
Glycine             C                   2H5N0O2             75.0664

nbulajic@matrix:~> a.out
Element: Threonine Found!
1012 years has passed.
Name                 Formula              Weight
Threonine           C                   4H9N0O3            119.1188
a.out
nbulajic@matrix:~> a.out
Element: Aspartic acid Found!
237 years has passed.
Name                 Formula              Weight
Aspartic acid       C                   4H7N0O4            133.1024

3. Based on the results of running your program, do you think it is likely
   that amino acids (the building blocks of life) would be created?
   Despite the amount of years that have passed ,the amino acids still produce life whih makes them a highly likely ogf being builing blocks of life.
4. If your program did generate amino acids, is there any correlation between
   those most frequently produced and the complexity (number of atoms) in the
   amino acid?
Yes,there is a corelationn between the most frequently prduced atoms and the complexity number of acids in amino acids as the more the atoms the more chance of amino acids reaching the mass of amino acids with the smallest mass.




\*



