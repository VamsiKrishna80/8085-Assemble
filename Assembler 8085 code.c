#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Instruction_Line(char *Instruct); //A line in Instruction Set
void Error(void);
unsigned int HexCode; // OPCODE


unsigned int First_char_M(char *Instrct);
unsigned int First_char_A(char *Instrct);
unsigned int First_char_C(char *Instrct);
unsigned int First_char_D(char *Instrct);

unsigned int First_char_I(char *Instrct);
//unsigned int First_char_J(char *Instrct);
//unsigned int First_char_L(char *Instrct);
unsigned int First_char_R(char *Instrct);

unsigned int First_char_S(char *Instrct);
unsigned int First_char_X(char *Instrct);
//unsigned int First_char_P(char *Instrct);
unsigned int First_char_O(char *Instrct);

//unsigned int First_char_N(char *Instrct);
//unsigned int First_char_E(char *Instrct);
//unsigned int First_char_H(char *Instrct);

void main()
{
    unsigned char First_chr;
    FILE *read=NULL,*write=NULL;
    char Instruct[10];
    unsigned char HexCode;
    read=fopen("abc.asm","r");
    write=fopen("abc.bin","w");
    if(read == NULL || write == NULL)
    {
        Error();
        exit(1);
    }
    while(!feof(read))
    {
         fgets(Instruct,100,read);
         HexCode=Instruction_Line(Instruct);
         printf("%X\n",HexCode);
         fprintf(write,"%X\n",HexCode);
    }
    fclose(read);
    fclose(write);

}
void Error(void)
{
    printf("ERROR\n");
}
int Instruction_Line(char *Instruct)
{
     unsigned int Hexcode;
    if(Instruct[0]=='A')
    {
        Hexcode = First_char_A(Instruct);
    }
    else if(Instruct[0]=='O')
    {
        Hexcode = First_char_O(Instruct);
    }
    else if(Instruct[0]=='I')
    {
        Hexcode = First_char_I(Instruct);
    }
    else if(Instruct[0]=='S')
    {
        Hexcode = First_char_S(Instruct);
    }
    else if(Instruct[0]=='M')
    {
        Hexcode = First_char_M(Instruct);
    }else if(Instruct[0]=='D')
    {
        Hexcode = First_char_D(Instruct);
    }
    else if(Instruct[0]=='R')
    {
        Hexcode = First_char_R(Instruct);
    }
    else if(Instruct[0]=='X')
    {
        Hexcode = First_char_X(Instruct);
    }
    else if(Instruct[0]=='X')
    {
        Hexcode = First_char_C(Instruct);
    }
        if(Hexcode != 0) return Hexcode;
        else return 0;

}

/*****************************************************************************************************************************************/
                          ////  Letter " M " //// 63
/*****************************************************************************************************************************************/

unsigned int First_char_M(char *Instruct)
{
    char data1[100];
    strcpy(data1,Instruct);
    if(data1[0] == 'M' && data1[1] == 'O' && data1[2] == 'V' && data1[3] == ' ')
    {
          if(data1[4] == 'A' && data1[5]==',' && data1[6] == 'A')return HexCode=0x7F;
          else if(data1[4] == 'A' && data1[5]==',' && data1[6] == 'B')return HexCode=0x78;
          else if(data1[4] == 'A' && data1[5]==',' && data1[6] == 'C')return HexCode=0x79;
          else if(data1[4] == 'A' && data1[5]==',' && data1[6] == 'D')return HexCode=0x7A;
          else if(data1[4] == 'A' && data1[5]==',' && data1[6] == 'E')return HexCode=0x7B;
          else if(data1[4] == 'A' && data1[5]==',' && data1[6] == 'H')return HexCode=0x7C;
          else if(data1[4] == 'A' && data1[5]==',' && data1[6] == 'L')return HexCode=0x7D;
          else if(data1[4] == 'A' && data1[5]==',' && data1[6] == 'M')return HexCode=0x7E;
          else if(data1[4] == 'B' && data1[5]==',' && data1[6] == 'A')return HexCode=0x47;
          else if(data1[4] == 'B' && data1[5]==',' && data1[6] == 'B')return HexCode=0x40;
          else if(data1[4] == 'B' && data1[5]==',' && data1[6] == 'C')return HexCode=0x41;
          else if(data1[4] == 'B' && data1[5]==',' && data1[6] == 'D')return HexCode=0x42;
          else if(data1[4] == 'B' && data1[5]==',' && data1[6] == 'E')return HexCode=0x43;
          else if(data1[4] == 'B' && data1[5]==',' && data1[6] == 'H')return HexCode=0x44;
          else if(data1[4] == 'B' && data1[5]==',' && data1[6] == 'L')return HexCode=0x45;
          else if(data1[4] == 'B' && data1[5]==',' && data1[6] == 'M')return HexCode=0x46;
          else if(data1[4] == 'C' && data1[5]==',' && data1[6] == 'A')return HexCode=0x4F;
          else if(data1[4] == 'C' && data1[5]==',' && data1[6] == 'B')return HexCode=0x48;
          else if(data1[4] == 'C' && data1[5]==',' && data1[6] == 'C')return HexCode=0x49;
          else if(data1[4] == 'C' && data1[5]==',' && data1[6] == 'D')return HexCode=0x4A;
          else if(data1[4] == 'C' && data1[5]==',' && data1[6] == 'E')return HexCode=0x4B;
          else if(data1[4] == 'C' && data1[5]==',' && data1[6] == 'H')return HexCode=0x4C;
          else if(data1[4] == 'C' && data1[5]==',' && data1[6] == 'L')return HexCode=0x4D;
          else if(data1[4] == 'C' && data1[5]==',' && data1[6] == 'M')return HexCode=0x4E;
          else if(data1[4] == 'D' && data1[5]==',' && data1[6] == 'A')return HexCode=0x57;
          else if(data1[4] == 'D' && data1[5]==',' && data1[6] == 'B')return HexCode=0x50;
          else if(data1[4] == 'D' && data1[5]==',' && data1[6] == 'C')return HexCode=0x51;
          else if(data1[4] == 'D' && data1[5]==',' && data1[6] == 'D')return HexCode=0x52;
          else if(data1[4] == 'D' && data1[5]==',' && data1[6] == 'E')return HexCode=0x53;
          else if(data1[4] == 'D' && data1[5]==',' && data1[6] == 'H')return HexCode=0x54;
          else if(data1[4] == 'D' && data1[5]==',' && data1[6] == 'L')return HexCode=0x55;
          else if(data1[4] == 'D' && data1[5]==',' && data1[6] == 'M')return HexCode=0x56;
          else if(data1[4] == 'E' && data1[5]==',' && data1[6] == 'A')return HexCode=0x5F;
          else if(data1[4] == 'E' && data1[5]==',' && data1[6] == 'B')return HexCode=0x58;
          else if(data1[4] == 'E' && data1[5]==',' && data1[6] == 'C')return HexCode=0x59;
          else if(data1[4] == 'E' && data1[5]==',' && data1[6] == 'D')return HexCode=0x5A;
          else if(data1[4] == 'E' && data1[5]==',' && data1[6] == 'E')return HexCode=0x5B;
          else if(data1[4] == 'E' && data1[5]==',' && data1[6] == 'H')return HexCode=0x5C;
          else if(data1[4] == 'E' && data1[5]==',' && data1[6] == 'L')return HexCode=0x5D;
          else if(data1[4] == 'E' && data1[5]==',' && data1[6] == 'M')return HexCode=0x5E;
          else if(data1[4] == 'H' && data1[5]==',' && data1[6] == 'A')return HexCode=0x67;
          else if(data1[4] == 'H' && data1[5]==',' && data1[6] == 'B')return HexCode=0x60;
          else if(data1[4] == 'H' && data1[5]==',' && data1[6] == 'C')return HexCode=0x61;
          else if(data1[4] == 'H' && data1[5]==',' && data1[6] == 'D')return HexCode=0x62;
          else if(data1[4] == 'H' && data1[5]==',' && data1[6] == 'E')return HexCode=0x63;
          else if(data1[4] == 'H' && data1[5]==',' && data1[6] == 'H')return HexCode=0x64;
          else if(data1[4] == 'H' && data1[5]==',' && data1[6] == 'L')return HexCode=0x65;
          else if(data1[4] == 'H' && data1[5]==',' && data1[6] == 'M')return HexCode=0x66;
          else if(data1[4] == 'L' && data1[5]==',' && data1[6] == 'A')return HexCode=0x6F;
          else if(data1[4] == 'L' && data1[5]==',' && data1[6] == 'B')return HexCode=0x68;
          else if(data1[4] == 'L' && data1[5]==',' && data1[6] == 'C')return HexCode=0x69;
          else if(data1[4] == 'L' && data1[5]==',' && data1[6] == 'D')return HexCode=0x6A;
          else if(data1[4] == 'L' && data1[5]==',' && data1[6] == 'E')return HexCode=0x6B;
          else if(data1[4] == 'L' && data1[5]==',' && data1[6] == 'H')return HexCode=0x6C;
          else if(data1[4] == 'L' && data1[5]==',' && data1[6] == 'L')return HexCode=0x6D;
          else if(data1[4] == 'L' && data1[5]==',' && data1[6] == 'M')return HexCode=0x6E;
          else if(data1[4] == 'M' && data1[5]==',' && data1[6] == 'A')return HexCode=0x77;
          else if(data1[4] == 'M' && data1[5]==',' && data1[6] == 'B')return HexCode=0x70;
          else if(data1[4] == 'M' && data1[5]==',' && data1[6] == 'C')return HexCode=0x71;
          else if(data1[4] == 'M' && data1[5]==',' && data1[6] == 'D')return HexCode=0x72;
          else if(data1[4] == 'M' && data1[5]==',' && data1[6] == 'E')return HexCode=0x73;
          else if(data1[4] == 'M' && data1[5]==',' && data1[6] == 'H')return HexCode=0x74;
          else if(data1[4] == 'M' && data1[5]==',' && data1[6] == 'L')return HexCode=0x75;
        else return 0;

    }
}

/*****************************************************************************************************************************************/
                          ////  Letter " A " //// 24
/*****************************************************************************************************************************************/

unsigned int First_char_A(char *Instruct)
{
    char data1[100];
    strcpy(data1,Instruct);

    if(data1[0] == 'A' && data1[1] == 'D' && data1[2] == 'D' && data1[3] == ' ')
    {
        if(data1[4] == 'A') return HexCode=0x87;
        else if(data1[4] == 'B') return HexCode=0x80;
        else if(data1[4] == 'C') return HexCode=0x81;
        else if(data1[4] == 'D') return HexCode=0x82;
        else if(data1[4] == 'E') return HexCode=0x83;
        else if(data1[4] == 'H') return HexCode=0x84;
        else if(data1[4] == 'L') return HexCode=0x85;
        else if(data1[4] == 'M') return HexCode=0x86;
        else return 0;

    }
    else if(data1[0] == 'A' && data1[1] == 'D' && data1[2] == 'C' && data1[3] == ' ')
    {
        if(data1[4] == 'A') return HexCode=0x8F;
        else if(data1[4] == 'B') return HexCode=0x88;
        else if(data1[4] == 'C') return HexCode=0x89;
        else if(data1[4] == 'D') return HexCode=0x8A;
        else if(data1[4] == 'E') return HexCode=0x8B;
        else if(data1[4] == 'H') return HexCode=0x8C;
        else if(data1[4] == 'L') return HexCode=0x8D;
        else if(data1[4] == 'M') return HexCode=0x8E;
    }
     else if(data1[0] == 'A' && data1[1] == 'N' && data1[2] == 'A' && data1[3] == ' ')
    {
        if(data1[4] == 'A') HexCode=0xA7;
        else if(data1[4] == 'B')return HexCode=0xA0;
        else if(data1[4] == 'C') return HexCode=0xA1;
        else if(data1[4] == 'D')return HexCode=0xA2;
        else if(data1[4] == 'E') return HexCode=0xA3;
        else if(data1[4] == 'H')return HexCode=0xA4;
        else if(data1[4] == 'L') return HexCode=0xA5;
        else if(data1[4] == 'M') return HexCode=0xA6;
         else return 0;
    }
}

/*****************************************************************************************************************************************/
                          ////  Letter " C " //// 10
/*****************************************************************************************************************************************/

unsigned int First_char_C(char *Instruct)
{
     char data1[100],HexCode;
    strcpy(data1,Instruct);

     if(data1[0] == 'C' && data1[1] == 'M' && data1[2] == 'P' && data1[3] == ' ')
    {
        if(data1[4] == 'A')return HexCode=0xBF;
        else if(data1[4] == 'B') return HexCode=0xB8;
        else if(data1[4] == 'C')return HexCode=0xB9;
        else if(data1[4] == 'D')return HexCode=0xBA;
        else if(data1[4] == 'E')return HexCode=0xBB;
        else if(data1[4] == 'H')return HexCode=0xBC;
        else if(data1[4] == 'L')return HexCode=0xBD;
        else if(data1[4] == 'M')return HexCode=0xBE;
        else return 0;
    }
    else if(data1[0] == 'C' && data1[1] == 'M' && data1[2] == 'C')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
    return HexCode=0x3f;
    }
    else if(data1[0] == 'C' && data1[1] == 'M' && data1[2] == 'A')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
    return HexCode=0x2F;
    }
     else return 0;
}

/*****************************************************************************************************************************************/
                          ////  Letter " D " //// 16
/*****************************************************************************************************************************************/


unsigned int First_char_D(char *Instruct)
{
     char data1[100];
    strcpy(data1,Instruct);
    if(data1[0] == 'D' && data1[1] == 'C' && data1[2] == 'X' && data1[3] == ' ')
    {
        if(data1[4] == 'B') return HexCode=0x0B;
        else if(data1[4] == 'D') return HexCode=0x1B;
        else if(data1[4] == 'H')return HexCode=0x2B;
        else if(data1[4] == 'S' && data1[5] == 'P')return HexCode=0x3B;
        else return 0;
    }
    else if(data1[0] == 'D' && data1[1] == 'A' && data1[2] == 'D' && data1[3] == ' ')
    {
        if(data1[4] == 'B') return HexCode=0x09;
        else if(data1[4] == 'D')return HexCode=0x19;
        else if(data1[4] == 'H')return HexCode=0x29;
        else if(data1[4] == 'S' && data1[5] == 'P')return HexCode=0x39;
       else return 0;
    }
     else if(data1[0] == 'D' && data1[1] == 'C' && data1[2] == 'R' && data1[3] == ' ')
    {
        if(data1[4] == 'A')return HexCode=0x3D;
        else if(data1[4] == 'B')return HexCode=0x05;
        else if(data1[4] == 'C')return HexCode=0x0D;
        else if(data1[4] == 'D')return HexCode=0x15;
        else if(data1[4] == 'E')return HexCode=0x1D;
        else if(data1[4] == 'H')return HexCode=0x25;
        else if(data1[4] == 'L')return HexCode=0x2D;
        else if(data1[4] == 'M')return HexCode=0x35;
       else return 0;
    }

}

/*****************************************************************************************************************************************/
                          ////  Letter " I " //// 12
/*****************************************************************************************************************************************/

unsigned int First_char_I(char *Instruct)
{
  char data1[100];
    strcpy(data1,Instruct);

    if(data1[0] == 'I' && data1[1] == 'N' && data1[2] == 'R' && data1[3] == ' ')
    {
        if(data1[4] == 'A')return HexCode=0x3C;
        else if(data1[4] == 'B')return HexCode=0x04;
        else if(data1[4] == 'C')return HexCode=0x0C;
        else if(data1[4] == 'D')return HexCode=0x14;
        else if(data1[4] == 'E')return HexCode=0x1C;
        else if(data1[4] == 'H')return HexCode=0x24;
        else if(data1[4] == 'L')return HexCode=0x2C;
        else if(data1[4] == 'M')return HexCode=0x34;
        else return 0;

    }
    else if(data1[0] == 'I' && data1[1] == 'N' && data1[2] == 'X' && data1[3] == ' ')
    {
        if(data1[4] == 'B')return HexCode=0x03;
        else if(data1[4] == 'D')return HexCode=0x13;
        else if(data1[4] == 'H')return HexCode=0x23;
        else if(data1[4] == 'S' && data1[5] == 'P') return HexCode=0x33;
        else return 0;
    }
}

/*****************************************************************************************************************************************/
                          ////  Letter " J " ////
/*****************************************************************************************************************************************/

//unsigned int First_char_J(char *Instrct);

/*****************************************************************************************************************************************/
                          ////  Letter " L " ////
/*****************************************************************************************************************************************/

//unsigned int First_char_L(char *Instrct);

/*****************************************************************************************************************************************/
                          ////  Letter " R " //// 5
/*****************************************************************************************************************************************/

unsigned int First_char_R(char *Instruct)
{
     char data1[100],Hexcode;
    strcpy(data1,Instruct);
    if(data1[0] == 'R' && data1[1] == 'S' && data1[2] == 'T' && data1[3] == ' ')
    {
        if(data1[4] == '0')return HexCode=0xC7;
        else if(data1[4] == '1')return HexCode=0xCF;
        else if(data1[4] == '2')return HexCode=0xD7;
        else if(data1[4] == '3')return HexCode=0xDF;
        else if(data1[4] == '4')return HexCode=0xE7;
        else if(data1[4] == '5')return HexCode=0xEF;
        else if(data1[4] == '6')return HexCode=0xF7;
        else if(data1[4] == '7')return HexCode=0xFF;
       else return 0;

    }
    else if(data1[0] == 'R' && data1[1] == 'L' && data1[2] == 'C')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
    return Hexcode=0x07;
    }
    else if(data1[0] == 'R' && data1[1] == 'R' && data1[2] == 'C')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
   return Hexcode=0x0f;
    }
     else if(data1[0] == 'R' && data1[1] == 'A' && data1[2] == 'L')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
   return Hexcode=0x17;
    }
     else if(data1[0] == 'R' && data1[1] == 'A' && data1[2] == 'R')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
   return Hexcode=0x17;
    }
     else if(data1[0] == 'R' && data1[1] == 'A' && data1[2] == 'R')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
   return Hexcode=0x1f;
    }
     else if(data1[0] == 'R' && data1[1] == 'E' && data1[2] == 'T')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
   return Hexcode=0xC9;
    }
     else if(data1[0] == 'R' && data1[1] == 'I' && data1[2] == 'M')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
   return Hexcode=0x20;
    }
     else if(data1[0] == 'R' && data1[1] == 'N' && data1[2] == 'C')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
   return Hexcode=0xD0;
    }
     else if(data1[0] == 'R' && data1[1] == 'N' && data1[2] == 'Z')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
   return Hexcode=0xC0;
    }
     else if(data1[0] == 'R' && data1[1] == 'P' && data1[2] == 'E')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
   return Hexcode=0xE8;
    }
     else if(data1[0] == 'R' && data1[1] == 'P' && data1[2] == 'O')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
   return Hexcode=0xE0;
    }
     else if(data1[0] == 'R' && data1[1] == 'C')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
   return Hexcode=0xD8;
    }
     else if(data1[0] == 'R' && data1[1] == 'P')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
   return Hexcode=0xF0;
    }
     else return 0;
}

/*****************************************************************************************************************************************/
                          ////  Letter " S " //// 17
/*****************************************************************************************************************************************/

unsigned int First_char_S(char *Instruct)
{
    char data1[100],Hexcode;
    strcpy(data1,Instruct);

    if(data1[0] == 'S' && data1[1] == 'U' && data1[2] == 'B' && data1[3] == ' ')
    {
        if(data1[4] == 'A')return HexCode=0x97;
        else if(data1[4] == 'B')return HexCode=0x90;
        else if(data1[4] == 'C')return HexCode=0x91;
        else if(data1[4] == 'D')return HexCode=0x92;
        else if(data1[4] == 'E')return HexCode=0x93;
        else if(data1[4] == 'H')return HexCode=0x94;
        else if(data1[4] == 'L')return HexCode=0x95;
        else if(data1[4] == 'M')return HexCode=0x96;
       else return 0;

    }
    else if(data1[0] == 'S' && data1[1] == 'B' && data1[2] == 'B' && data1[3] == ' ')
    {
        if(data1[4] == 'A')return HexCode=0x8F;
        else if(data1[4] == 'B')return HexCode=0x98;
        else if(data1[4] == 'C')return HexCode=0x99;
        else if(data1[4] == 'D')return HexCode=0x9A;
        else if(data1[4] == 'E')return HexCode=0x9B;
        else if(data1[4] == 'H')return HexCode=0x9C;
        else if(data1[4] == 'L')return HexCode=0x9D;
        else if(data1[4] == 'M')return HexCode=0x9E;
      else return 0;
    }
    else if(data1[0] == 'S' && data1[1] == 'T' && data1[2] == 'C')
    {
        for(int i=3;data1[i]!='\n';i++)
    {
        if(data1[i]!=' ') Error();
        break;
    }
   return Hexcode=0x37;
    }
     else return 0;

}

/*****************************************************************************************************************************************/
                          ////  Letter " X " //// 8
/*****************************************************************************************************************************************/

unsigned int First_char_X(char *Instruct)
{
    char data1[100],Hexcode;
    strcpy(data1,Instruct);

    if(data1[0] == 'X' && data1[1] == 'R' && data1[2] == 'A' && data1[3] == ' ')
    {
        if(data1[4] == 'A')return HexCode=0xA7;
        else if(data1[4] == 'B')return HexCode=0xA8;
        else if(data1[4] == 'C')return HexCode=0xA9;
        else if(data1[4] == 'D')return HexCode=0xAA;
        else if(data1[4] == 'E')return HexCode=0xAB;
        else if(data1[4] == 'H')return HexCode=0xAC;
        else if(data1[4] == 'L')return HexCode=0xAD;
        else if(data1[4] == 'M')return HexCode=0xAE;
         else return 0;
    }
}


/*****************************************************************************************************************************************/
                          ////  Letter " P " ////
/*****************************************************************************************************************************************/

unsigned int First_char_P(char *Instruct)
{
    char data1[100],Hexcode;
    strcpy(data1,Instruct);

    if(data1[0] == 'P' && data1[1] == 'O' && data1[2] == 'P' && data1[3] == ' ')
    {
        if(data1[4] == 'B')return HexCode=0xC1;
        else if(data1[4] == 'D')return HexCode=0xD1;
        else if(data1[4] == 'H')return HexCode=0xE1;
        else if(data1[4] == 'E' && data1[5] == 'P' && data1[6] == 'S' && data1[7] == 'W' )return HexCode=0xF1;
    }
    else if(data1[0] == 'P' && data1[1] == 'U' && data1[2] == 'S' && data1[3] == 'H' && data1[4] == ' ')
    {
        if(data1[5] == 'B')return HexCode=0xC5;
        else if(data1[5] == 'D')return HexCode=0xD5;
        else if(data1[5] == 'H')return HexCode=0xE5;
        else if(data1[5] == 'E' && data1[6] == 'P' && data1[7] == 'S' && data1[8] == 'W' )return HexCode=0xF5;
    }
    else return 0;
}

/*****************************************************************************************************************************************/
                          ////  Letter " O " //// 8
/*****************************************************************************************************************************************/

unsigned int First_char_O(char
                           *Instruct)
{
    char data1[100],Hexcode;
    strcpy(data1,Instruct);

    if(data1[0] == 'O' && data1[1] == 'R' && data1[2] == 'A' && data1[3] == ' ')
    {
        if(data1[4] == 'A')return HexCode=0xB7;
        else if(data1[4] == 'B')return HexCode=0xB0;
        else if(data1[4] == 'C')return HexCode=0xB1;
        else if(data1[4] == 'D')return HexCode=0xB2;
        else if(data1[4] == 'E')return HexCode=0xB3;
        else if(data1[4] == 'H')return HexCode=0xB4;
        else if(data1[4] == 'L')return HexCode=0xB5;
        else if(data1[4] == 'M')return HexCode=0xB6;
    }
    else return 0;
}
