#include<stdio.h>
#include<stdlib.h>
#include<string.h>

short start_line_number=1;
short Starting_Address=0x1000;
char comment_flag;
char check_data(char *ptr);
void Error(void);
void label_Error(void);
void Data_Error(void);
void Comma_Error(void);
void Address_Error(void);
char *skip_spaces(char *ptr);
char Find_comment(char *ptr);
char *Find_comma(char *ptr);
char label_check(char *Start,char *End);
char *Data_Store(char *ptr);
char *detect_colon(char *ptr);
char detect_levels(char *ptr);
char *Find_address(char *ptr);
char *Find_level_name_and_address(char *ptr);
char convert_decimal_to_hex(char nibble);
void store_the_address(short address);
char *store_level_address_and_name(char *Start,char *End);
void Instruction_Line(char *Instruct);
void Detect_Remain(char *ptr);
void update_data1(char *ptr);



char error_flag=0;
void First_char_O(char *Instruct);
void First_char_A(char *Instruct);
void First_char_C(char *Instruct);
void First_char_D(char *Instruct);
void First_char_E(char *Instruct);
void First_char_I(char *Instruct);
void First_char_J(char *Instruct);
void First_char_L(char *Instruct);
void First_char_M(char *Instruct);
void First_char_H(char *Instruct);
void First_char_N(char *Instruct);
void First_char_R(char *Instruct);
void First_char_P(char *Instruct);
void First_char_S(char *Instruct);
void First_char_X(char *Instruct);

unsigned short memory_address;                  
unsigned short line_number=0;
char LABEL_NUMBER=0;
char LSB_byte_address[3];
char MSB_byte_address[3];
short int lineNumber=0;
char instruction_size=0;
char label_name[20][20];
unsigned short label_address[20];
char *ptr0,*ptr1,*ptr2,*ptr3,*ptr4;
char data[5];
short level_number = 0;
unsigned short HexCode; // OPCODE


char colon_flag=1;

void Error(void)
{
    printf("ERROR line Number:%d",line_number);
     instruction_size = 0;
    error_flag=1;
}
void label_Error(void)
{
    printf("\n line number %d :: label name should be letters , numbers and underscore only\n",line_number);
    instruction_size = 0;
   error_flag=1;
}

void Data_Error(void)
{
    printf("\n line number %d :: Data should be letters(A to F) , numbers only\n",line_number);
    error_flag=1;
    instruction_size = 0;
}
void Comma_Error(void)
{
    printf("\nline number %d :: Comma Errror \n",line_number);
   error_flag=1;
   instruction_size = 0;
}
void Address_Error(void)
{
    printf("\n line number %d :: Address Errror \n",line_number);
    instruction_size = 0;
    error_flag=1;
}
char *skip_spaces(char *ptr)
{
    while((*ptr==' '))
    {
        ptr++;
    }
    return ptr;
}
char Find_comment(char *ptr)
{
    char *copyptr,comment_flag=0;
    copyptr=ptr;
    ptr=skip_spaces(ptr);
    if(*ptr==';')return comment_flag=1;
    else return comment_flag=0;
}

char *Find_comma(char *ptr)
{
    ptr=skip_spaces(ptr);
    if(*ptr==',')
    {
        return (ptr+1);
    }
    else
    {
      Comma_Error();
    }
}
char label_check(char *Start,char *End)
{
    char *ptr;
    ptr=Start;
    while((*ptr!=*End) || (*ptr!=' '))
    {
        if(*ptr>='A' || *ptr<='Z' || *ptr>='a' || *ptr>='z' || *ptr>='0' || *ptr<='9' || *ptr>='_') ptr++;
        else label_Error();
        ptr++;
    }
    End=ptr;
    if(*ptr==':')return 1;
    else return 0;
}

char *Data_Store(char *ptr)
{
    char *copyptr,True=0;
    copyptr=ptr;
    True=check_data(ptr);
    if(True)
    {
        data[0]=*copyptr;
        copyptr++;
        data[1]=*copyptr;
        data[2]='\n';
        copyptr=copyptr+2;
        return copyptr;
    }
    else Data_Error();
}
char *detect_colon(char *ptr){

  ptr = skip_spaces(ptr);
  while(*ptr != 0){
  if(*ptr == ':') break;
  ptr++;
  }
  return ptr;
}

char check_data(char *ptr)
{
    ptr=skip_spaces(ptr);
    update_data1(ptr);
    if(*ptr2=='h' || *ptr2=='H')
    {
        if((*ptr0 >='A' && *ptr0<='F') || (*ptr0>='a' && *ptr0>='F' ) || (*ptr0 >'0' && *ptr0<='9'));
        else return 0;
        if((*ptr0 >='A' && *ptr0<='F') || (*ptr0>='a' && *ptr0>='F' ) || (*ptr0 >='0' && *ptr0<='9')) return 1;
        else return 0;
    }
    else
    {
        return 0;
    }
}
char detect_levels(char *ptr){

  char instruction_size = 0;
  ptr = skip_spaces(ptr);

  if(Find_comment(ptr)) goto skip; // detecting the line is comment or not
  char *colon_ptr = detect_colon(ptr);                                        
  if(*colon_ptr == ':')  ptr = store_level_address_and_name(ptr, colon_ptr);     
   ptr = skip_spaces(ptr);
  update_data1(ptr);

       if(*ptr0 == 'A'){
             if((*ptr1 == 'C') && (*ptr2 == 'I') && (*ptr3 == ' ')) instruction_size = 2;
        else if((*ptr1 == 'D') && (*ptr2 == 'C') && (*ptr3 == ' ')) instruction_size = 1;
        else if((*ptr1 == 'D') && (*ptr2 == 'D') && (*ptr3 == ' ')) instruction_size = 1;
        else if((*ptr1 == 'D') && (*ptr2 == 'I') && (*ptr3 == ' ')) instruction_size = 2;
        else if((*ptr1 == 'N') && (*ptr2 == 'A') && (*ptr3 == ' ')) instruction_size = 1;
        else if((*ptr1 == 'N') && (*ptr2 == 'I') && (*ptr3 == ' ')) instruction_size = 2;
        else
      {
         // printf("A ");
          Error();
      }
       }
  else if(*ptr0 == 'C'){
             if((*ptr1 == 'A') && (*ptr2 == 'L') && (*ptr3 == 'L') && (*ptr4 == ' ')) instruction_size = 3;
        else if((*ptr1 == 'C') && (*ptr2 == ' '))                                     instruction_size = 3;
        else if((*ptr1 == 'M') && (*ptr2 == 'A'))                                     instruction_size = 1;
        else if((*ptr1 == 'M') && (*ptr2 == 'C'))                                     instruction_size = 1;
        else if((*ptr1 == 'M') && (*ptr2 == 'P') && (*ptr3 == ' '))                   instruction_size = 1;
        else if((*ptr1 == 'M') && (*ptr2 == ' '))                                     instruction_size = 3;
        else if((*ptr1 == 'N') && (*ptr2 == 'C') && (*ptr3 == ' '))                   instruction_size = 3;
        else if((*ptr1 == 'N') && (*ptr2 == 'Z') && (*ptr3 == ' '))                   instruction_size = 3;
        else if((*ptr1 == 'P') && (*ptr2 == 'E') && (*ptr3 == ' '))                   instruction_size = 3;
        else if((*ptr1 == 'P') && (*ptr2 == 'I') && (*ptr3 == ' '))                   instruction_size = 2;
        else if((*ptr1 == 'P') && (*ptr2 == 'O') && (*ptr3 == ' '))                   instruction_size = 3;
        else if((*ptr1 == 'P') && (*ptr2 == ' '))                                     instruction_size = 3;
        else if((*ptr1 == 'Z') && (*ptr2 == ' '))                                     instruction_size = 3;
       else
      {
          //printf("C");
          Error();
      }
  }
  else if(*ptr0 == 'D'){
             if((*ptr1 == 'A') && (*ptr2 == 'A'))                   instruction_size = 1;
        else if((*ptr1 == 'A') && (*ptr2 == 'D') && (*ptr3 == ' ')) instruction_size = 1;
        else if((*ptr1 == 'C') && (*ptr2 == 'R') && (*ptr3 == ' ')) instruction_size = 1;
        else if((*ptr1 == 'C') && (*ptr2 == 'X') && (*ptr3 == ' ')) instruction_size = 1;
        else if(*ptr1 == 'I')                                       instruction_size = 1;
        else
      {
         // printf("D");
          Error();
      }
  }
  else if((*ptr0 == 'E') && (*ptr1 == 'I'))                         instruction_size = 1;
  else if((*ptr0 == 'H') && (*ptr1 == 'L') && (*ptr2 == 'T'))       instruction_size = 1;

  else if(*ptr0 == 'I'){
             if((*ptr1 == 'N') && (*ptr2 == 'R') && (*ptr3 == ' ')) instruction_size = 1;
        else if((*ptr1 == 'N') && (*ptr2 == 'X') && (*ptr3 == ' ')) instruction_size = 1;
        else if((*ptr1 == 'N') && (*ptr2 == ' '))                    instruction_size = 2;
       else
      {
         // printf("I");
          Error();
      }
  }
  else if(*ptr0 == 'J'){
             if((*ptr1 == 'C') && (*ptr2 == ' '))                   instruction_size = 3;
        else if((*ptr1 == 'M') && (*ptr2 == 'P') && (*ptr3 == ' ')) instruction_size = 3;
        else if((*ptr1 == 'M') && (*ptr2 == ' '))                   instruction_size = 3;
        else if((*ptr1 == 'N') && (*ptr2 == 'C') && (*ptr3 == ' ')) instruction_size = 3;
        else if((*ptr1 == 'N') && (*ptr2 == 'Z') && (*ptr3 == ' ')) instruction_size = 3;
        else if((*ptr1 == 'P') && (*ptr2 == 'E') && (*ptr3 == ' ')) instruction_size = 3;
        else if((*ptr1 == 'P') && (*ptr2 == 'O') && (*ptr3 == ' ')) instruction_size = 3;
        else if((*ptr1 == 'P') && (*ptr2 == ' '))                   instruction_size = 3;
        else if((*ptr1 == 'Z') && (*ptr2 == ' '))                   instruction_size = 3;
        else
      {
         // printf("J");
          Error();
      }
  }
  else if(*ptr0 == 'L'){
             if((*ptr1 == 'D') && (*ptr2 == 'A') && (*ptr3 == 'X') && (*ptr4 == ' ')) instruction_size = 1;
        else if((*ptr1 == 'D') && (*ptr2 == 'A') && (*ptr3 == ' '))                   instruction_size = 3;
        else if((*ptr1 == 'H') && (*ptr2 == 'L') && (*ptr3 == 'D') && (*ptr4 == ' ')) instruction_size = 3;
        else if((*ptr1 == 'X') && (*ptr2 == 'I') && (*ptr3 == ' '))                   instruction_size = 3;
        else
      {
         // printf("L");
          Error();
      }
  }
  else if(*ptr0 == 'M'){
             if((*ptr1 == 'O') && (*ptr2 == 'V') && (*ptr3 == ' '))
             {
                 instruction_size = 1;
             }
        else if((*ptr1 == 'V') && (*ptr2 == 'I') && (*ptr3 == ' ')) instruction_size = 2;
      else
      {
         // printf("M");
          Error();
      }
  }
  else if((*ptr0 == 'N') && (*ptr1 == 'O') && (*ptr2 == 'P'))       instruction_size = 1;

  else if(*ptr0 == 'O'){
             if((*ptr1 == 'R') && (*ptr2 == 'A') && (*ptr3 == ' ')) instruction_size = 1;
        else if((*ptr1 == 'R') && (*ptr2 == 'I') && (*ptr3 == ' ')) instruction_size = 2;
        else if((*ptr1 == 'U') && (*ptr2 == 'T') && (*ptr3 == ' ')) instruction_size = 2;
        else
      {
          //printf("O");
          Error();
      }
  }
  else if(*ptr0 == 'P'){
             if((*ptr1 == 'C') && (*ptr2 == 'H') && (*ptr3 == 'L'))                   instruction_size = 1;
        else if((*ptr1 == 'O') && (*ptr2 == 'P') && (*ptr3 == ' '))                   instruction_size = 1;
        else if((*ptr1 == 'U') && (*ptr2 == 'S') && (*ptr3 == 'H') && (*ptr4 == ' ')) instruction_size = 1;
       else
      {
          //printf("P");
          Error();
      }
  }
  else if(*ptr0 == 'R'){
             if((*ptr1 == 'A') && (*ptr2 == 'L'))     instruction_size = 1;
        else if((*ptr1 == 'A') && (*ptr2 == 'R'))     instruction_size = 1;
        else if (*ptr1 == 'C')                        instruction_size = 1;
        else if((*ptr1 == 'E') && (*ptr2 == 'T'))     instruction_size = 1;
        else if((*ptr1 == 'I') && (*ptr2 == 'M'))     instruction_size = 1;
        else if((*ptr1 == 'L') && (*ptr2 == 'C'))     instruction_size = 1;
        else if (*ptr1 == 'M')                        instruction_size = 1;
        else if((*ptr1 == 'N') && (*ptr2 == 'C'))     instruction_size = 1;
        else if((*ptr1 == 'N') && (*ptr2 == 'Z'))     instruction_size = 1;
        else if((*ptr1 == 'P') && (*ptr2 == 'E'))     instruction_size = 1;
        else if((*ptr1 == 'P') && (*ptr2 == 'O'))     instruction_size = 1;
        else if (*ptr1 == 'P')                        instruction_size = 1;
        else if((*ptr1 == 'R') && (*ptr2 == 'C'))     instruction_size = 1;
        else if((*ptr1 == 'S') && (*ptr2 == 'T') && (*ptr3 == ' ')) instruction_size = 1;
        else if (*ptr1 == 'Z')                         instruction_size = 1;
        else
      {
        //  printf("R");
          Error();
      }
  }
  else if(*ptr0 == 'S'){
             if((*ptr1 == 'B') && (*ptr2 == 'B') && (*ptr3 == ' '))                   instruction_size = 1;
        else if((*ptr1 == 'B') && (*ptr2 == 'I') && (*ptr3 == ' '))                   instruction_size = 2;
        else if((*ptr1 == 'H') && (*ptr2 == 'L') && (*ptr3 == 'D') && (*ptr4 == ' ')) instruction_size = 3;
        else if((*ptr1 == 'I') && (*ptr2 == 'M') && (*ptr3 == ' '))                   instruction_size = 1;
        else if((*ptr1 == 'P') && (*ptr2 == 'H') && (*ptr3 == 'L') && (*ptr4 == ' ')) instruction_size = 1;
        else if((*ptr1 == 'T') && (*ptr2 == 'A') && (*ptr3 == 'X') && (*ptr4 == ' ')) instruction_size = 1;
        else if((*ptr1 == 'T') && (*ptr2 == 'A') && (*ptr3 == ' '))                   instruction_size = 3;
        else if((*ptr1 == 'T') && (*ptr2 == 'C'))                                     instruction_size = 1;
        else if((*ptr1 == 'U') && (*ptr2 == 'B') && (*ptr3 == ' '))                   instruction_size = 1;
        else if((*ptr1 == 'U') && (*ptr2 == 'I') && (*ptr3 == ' '))                   instruction_size = 2;
        else
      {
         // printf("S");
          Error();
      }
  }
  else if(*ptr0 == 'X'){
             if((*ptr1 == 'C') && (*ptr2 == 'H') && (*ptr3 == 'G'))     instruction_size = 1;
        else if((*ptr1 == 'R') && (*ptr2 == 'A') && (*ptr3 == ' '))     instruction_size = 1;
        else if((*ptr1 == 'R') && (*ptr2 == 'I') && (*ptr3 == ' '))     instruction_size = 2;
        else if((*ptr1 == 'T') && (*ptr2 == 'H') && (*ptr3 == 'L'))     instruction_size = 1;
        else
      {
         // printf("X");
          Error();
      }
  }
  else
      {

          Error();
      }

skip:
  return instruction_size;
}
char check_address(char *ptr)
{
    update_data1(ptr);
    if(*ptr4=='h' || *ptr4=='H')
    {
        if((*ptr0 >='A' && *ptr0<='Z') || (*ptr0>='a' && *ptr0>='z' ) || (*ptr0 >='0' && *ptr0<='9'));
        else return 0;
        if((*ptr0 >='A' && *ptr0<='Z') || (*ptr0>='a' && *ptr0>='z' ) || (*ptr0 >='0' && *ptr0<='9'));
        else return 0;
        if((*ptr0 >='A' && *ptr0<='Z') || (*ptr0>='a' && *ptr0>='z' ) || (*ptr0 >='0' && *ptr0<='9'));
        else return 0;
        if((*ptr0 >='A' && *ptr0<='Z') || (*ptr0>='a' && *ptr0>='z' ) || (*ptr0 >='0' && *ptr0<='9')) return 1;
        else return 0;
    }
    else
    {
        return 0;
    }
}
char *Find_address(char *ptr)
{
    char True=0;
    True=check_address(ptr);
    update_data1(ptr);
    if(True)
    {
        MSB_byte_address[0]=*ptr0;
        MSB_byte_address[1]=*ptr1;
        MSB_byte_address[3]='\0';

        LSB_byte_address[0]=*ptr2;
        LSB_byte_address[1]=*ptr3;
        LSB_byte_address[2]='\0';
        instruction_size=3;
    }
    else
    {
        Address_Error();
    }
    ptr=ptr4+1;
    return ptr;
}
char *Find_level_name_and_address(char *ptr)
{
    char *copyptr,i=0;
    char copy_label[20]={0};
    char address_flag=0;
    char *ptr_store;
    short address;
    while(1)
    {
        if((*ptr==' ') || (*ptr=='\n' || (*ptr == 0)))break;
        copy_label[i]=*ptr;
        ptr++;
        i++;
    }
    copyptr=--ptr;
    for(char level_number=0;level_number<20;level_number++)
    {
        ptr_store=label_name[level_number];
        ptr=copy_label;
       if((strcmp(ptr_store,ptr))==0)
       {
           address=label_address[level_number];
           store_the_address(address);

           address_flag=1;
           instruction_size = 3;
           break;
       }
       else{
        address_flag=0;
       }
    }
    if(!address_flag)
    {
        Address_Error();
    }
    return copyptr+1;
}
char convert_decimal_to_hex_decimal(char chr){
  if(chr <= 9) 
  {
      chr += '0';  
  }
  else 
  {
      chr += '0' + 7;
  }
  return chr;
}

void store_the_address(short address){
  char chr_0, chr_1, chr_2, chr_3;

  
  chr_0 =  address & 0x000f;
  chr_1 = (address & 0x00f0) >> 4;
  chr_2 = (address & 0x0f00) >> 8;
  chr_3 = address >> 12;

 
  MSB_byte_address[0] = convert_decimal_to_hex_decimal(chr_3);
  MSB_byte_address[1] = convert_decimal_to_hex_decimal(chr_2);
  MSB_byte_address[2] = '\0';
  LSB_byte_address[0] = convert_decimal_to_hex_decimal(chr_1);
  LSB_byte_address[1] = convert_decimal_to_hex_decimal(chr_0);
  LSB_byte_address[2] = '\0';
}

char *store_level_address_and_name(char *Start,char *End)
{
   char *ptr,i;
   ptr=Start;
   while(*ptr!=*End)
   {
       label_name[LABEL_NUMBER][i]=*ptr;
       i++;
       ptr++;
   }
   label_address[LABEL_NUMBER]=memory_address;
   LABEL_NUMBER++;
   End++;
   End=skip_spaces(End);
   return End;
}
void Instruction_Line(char *Instruct)
{
     char *ptr,chr;
     ptr=Instruct;
     ptr=skip_spaces(ptr);
     if(Find_comment(ptr)){ comment_flag = 1; goto skip;}
     char *colon_ptr = detect_colon(ptr);                     
  if(*colon_ptr == ':') ptr = colon_ptr + 1;
  ptr = skip_spaces(ptr);
   chr=*ptr;
    if(chr=='A') First_char_A(ptr);
    else if(chr=='O') First_char_O(ptr);
    else if(chr=='L') First_char_L(ptr);
    else if(chr=='J') First_char_J(ptr);
    else if(chr=='P') First_char_P(ptr);
    else if(chr=='I') First_char_I(ptr);
    else if(chr=='S') First_char_S(ptr);
    else if(chr=='M') First_char_M(ptr);
    else if(chr=='D') First_char_D(ptr);
    else if(chr=='R') First_char_R(ptr);
    else if(chr=='X') First_char_X(ptr);
    else if(chr=='C') First_char_C(ptr);
    else if(chr=='E') First_char_E(ptr);
    else if(chr=='N') First_char_N(ptr);
    else if(chr=='H') First_char_H(ptr);
    else
    {
        Error();
    }
skip: ;

}

/*****************************************************************************************************************************************/

void update_data1(char *ptr)
{
   ptr0=ptr;
   ptr1=ptr + 1;
   ptr2=ptr + 2;
   ptr3=ptr + 3;
   ptr4=ptr + 4;
}
void Detect_Remain(char *ptr)
{
    ptr=skip_spaces(ptr);
    if(!(*ptr==';' || *ptr=='\n' || *ptr == 0)) Error();
}
/*****************************************************************************************************************************************/
                          ////  Letter " M " //// 63
/*****************************************************************************************************************************************/

void First_char_M(char *Instruct)
{
    char *ptr;
    update_data1(Instruct);
    if(*ptr0 == 'M' && *ptr1 == 'O' && *ptr2 == 'V' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4);
          if(*ptr == 'A')
          {
              ptr=Find_comma((ptr+1));
              ptr=skip_spaces(ptr);
              if(*ptr == 'A') HexCode=0x7F;
         else if(*ptr == 'B') HexCode=0x78;
         else if(*ptr == 'C') HexCode=0x79;
         else if(*ptr == 'D') HexCode=0x7A;
         else if(*ptr == 'E') HexCode=0x7B;
         else if(*ptr == 'H') HexCode=0x7C;
         else if(*ptr == 'L') HexCode=0x7D;
         else if(*ptr == 'M') HexCode=0x7E;
         else
           {
            Error();
           }
           ptr++;
        }
        else if(*ptr == 'B')
         {
             ptr=Find_comma((ptr+1));
             ptr=skip_spaces(ptr);
             if(*ptr == 'A')  HexCode=0x47;
        else if(*ptr == 'B')  HexCode=0x40;
        else if(*ptr == 'C')  HexCode=0x41;
        else if(*ptr == 'D')  HexCode=0x42;
        else if(*ptr == 'E') HexCode=0x43;
        else if(*ptr == 'H') HexCode=0x44;
        else if(*ptr == 'L') HexCode=0x45;
        else if(*ptr == 'M') HexCode=0x46;
        else
           {
            Error();
           }
           ptr++;
        }
       else if(*ptr == 'C')
        {
            ptr=Find_comma((ptr+1));
             ptr=skip_spaces(ptr);
             if(*ptr == 'A') HexCode=0x4F;
        else if(*ptr == 'B') HexCode=0x48;
        else if(*ptr == 'C') HexCode=0x49;
        else if(*ptr == 'D') HexCode=0x4A;
        else if(*ptr == 'E') HexCode=0x4B;
        else if(*ptr == 'H') HexCode=0x4C;
        else if(*ptr == 'L') HexCode=0x4D;
        else if(*ptr == 'M') HexCode=0x4E;
         else
           {
            Error();
           }
           ptr++;
        }
       else if(*ptr == 'D')
        {
           ptr=Find_comma((ptr+1));
             ptr=skip_spaces(ptr);
             if(*ptr == 'A') HexCode=0x57;
        else if(*ptr == 'B') HexCode=0x50;
        else if(*ptr == 'C') HexCode=0x51;
        else if(*ptr == 'D') HexCode=0x52;
        else if(*ptr == 'E') HexCode=0x53;
        else if(*ptr == 'H') HexCode=0x54;
        else if(*ptr == 'L') HexCode=0x55;
        else
           {
            Error();
           }
           ptr++;
        }
       else if(*ptr == 'E')
        {
            ptr=Find_comma((ptr+1));
             ptr=skip_spaces(ptr);
             if(*ptr == 'A') HexCode=0x5F;
        else if(*ptr == 'B') HexCode=0x58;
        else if(*ptr == 'C') HexCode=0x59;
        else if(*ptr == 'D') HexCode=0x5A;
        else if(*ptr == 'E') HexCode=0x5B;
        else if(*ptr == 'H') HexCode=0x5C;
        else if(*ptr == 'L') HexCode=0x5D;
        else if(*ptr == 'M') HexCode=0x5E;
        else
           {
            Error();
           }
           ptr++;
        }
       else if(*ptr == 'H')
        {
            ptr=Find_comma((ptr+1));
             ptr=skip_spaces(ptr);
             if(*ptr == 'A') HexCode=0x67;
        else if(*ptr == 'B') HexCode=0x60;
        else if(*ptr == 'C') HexCode=0x61;
        else if(*ptr == 'D') HexCode=0x62;
        else if(*ptr == 'E') HexCode=0x63;
        else if(*ptr == 'H') HexCode=0x64;
        else if(*ptr == 'L') HexCode=0x65;
        else if(*ptr == 'M') HexCode=0x66;
       else
           {
            Error();
           }
           ptr++;
        }
       else if(*ptr == 'L')
        {
            ptr=Find_comma((ptr+1));
             ptr=skip_spaces(ptr);
             if(*ptr == 'A') HexCode=0x6F;
        else if(*ptr == 'B') HexCode=0x68;
        else if(*ptr == 'C') HexCode=0x69;
        else if(*ptr == 'D') HexCode=0x6A;
        else if(*ptr == 'E') HexCode=0x6B;
        else if(*ptr == 'H') HexCode=0x6C;
        else if(*ptr == 'L') HexCode=0x6D;
        else if(*ptr == 'M') HexCode=0x6E;
        else
           {
            Error();
           }
        ptr++;
        }
       else if(*ptr == 'M')
        {

           ptr=Find_comma((ptr+1));
             ptr=skip_spaces(ptr);
               if(*ptr == 'A') HexCode=0x77;
        else if(*ptr == 'B') HexCode=0x70;
        else if(*ptr == 'C') HexCode=0x71;
        else if(*ptr == 'D') HexCode=0x72;
        else if(*ptr == 'E') HexCode=0x73;
        else if(*ptr == 'H') HexCode=0x74;
        else if(*ptr == 'L') HexCode=0x75;
       else
           {
            Error();
           }
        }
         else
           {
            Error();
           }
           ptr++;
        }
    else if(*ptr0 == 'M' && *ptr1 == 'V' && *ptr2 == 'I' && *ptr3 == ' ')
    {
        char True=0;
         instruction_size=2;
        ptr=skip_spaces(ptr4);
             if(*ptr == 'A') HexCode=0x77;
        else if(*ptr == 'B') HexCode=0x70;
        else if(*ptr == 'C') HexCode=0x71;
        else if(*ptr == 'D') HexCode=0x72;
        else if(*ptr == 'E') HexCode=0x73;
        else if(*ptr == 'H') HexCode=0x74;
        else if(*ptr == 'L') HexCode=0x75;
           else
           {
            instruction_size = 0;
            Error();
           }
                 ptr=Find_comma((ptr+1));
                 ptr=skip_spaces(ptr);
                 ptr=Data_Store(ptr);
                 Detect_Remain(ptr);
    }
    Detect_Remain(ptr);
}

/*****************************************************************************************************************************************/
                          ////  Letter " A " //// 24
/*****************************************************************************************************************************************/

void First_char_A(char *Instruct)
{
    char *ptr;
    update_data1(Instruct);
    if(*ptr0 == 'A' && *ptr1 == 'D' && *ptr2 == 'D' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4);
        if(*ptr == 'A') HexCode=0x87;
        else if(*ptr == 'B') HexCode=0x80;
        else if(*ptr == 'C') HexCode=0x81;
        else if(*ptr == 'D') HexCode=0x82;
        else if(*ptr == 'E') HexCode=0x83;
        else if(*ptr == 'H') HexCode=0x84;
        else if(*ptr == 'L') HexCode=0x85;
        else if(*ptr == 'M') HexCode=0x86;
      else
           {
            Error();
           }
           ptr++;
    }
    else if(*ptr0 == 'A' && *ptr1 == 'D' && *ptr2 == 'C' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4);
        if(*ptr == 'A') HexCode=0x8F;
        else if(*ptr == 'B') HexCode=0x88;
        else if(*ptr == 'C') HexCode=0x89;
        else if(*ptr == 'D') HexCode=0x8A;
        else if(*ptr == 'E') HexCode=0x8B;
        else if(*ptr == 'H') HexCode=0x8C;
        else if(*ptr == 'L') HexCode=0x8D;
        else if(*ptr == 'M') HexCode=0x8E;
       else
           {
            Error();
           }
           ptr++;
    }
     else if(*ptr0 == 'A' && *ptr1 == 'N' && *ptr2 == 'A' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4);
        if(*ptr == 'A') HexCode=0xA7;
        else if(*ptr == 'B') HexCode=0xA0;
        else if(*ptr == 'C') HexCode=0xA1;
        else if(*ptr == 'D') HexCode=0xA2;
        else if(*ptr == 'E') HexCode=0xA3;
        else if(*ptr == 'H') HexCode=0xA4;
        else if(*ptr == 'L') HexCode=0xA5;
        else if(*ptr == 'M') HexCode=0xA6;
        else
           {
            Error();
           }
           ptr++;
    }
     else if(*ptr0 == 'A' && *ptr1 == 'D' && *ptr2 == 'I' && *ptr3 == ' ')
    {
                 ptr=skip_spaces(ptr4);
                 ptr=Data_Store(ptr);
                 HexCode=0xC6;

    }
    else if(*ptr0 == 'A' && *ptr1 == 'C' && *ptr2 == 'I' && *ptr3 == ' ')
    {
                 ptr=skip_spaces(ptr4);
                 ptr=Data_Store(ptr);
                 HexCode=0xCE;

    }
    else if(*ptr0 == 'A' && *ptr1 == 'N' && *ptr2 == 'I' && *ptr3 == ' ')
    {
                 ptr=skip_spaces(ptr4);
                 ptr=Data_Store(ptr);
                 HexCode=0xE2;
    }
     else
           {
            Error();
           }
        Detect_Remain(ptr);
}

/*****************************************************************************************************************************************/
                          ////  Letter " C " //// 10
/*****************************************************************************************************************************************/

void First_char_C(char *Instruct)
{
    char *ptr,True;
     update_data1(Instruct);
     if(*ptr0 == 'C' && *ptr1 == 'M' && *ptr2 == 'P' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4);
        if(*ptr == 'A') HexCode=0xBF;
        else if(*ptr == 'B') HexCode=0xB8;
        else if(*ptr == 'C') HexCode=0xB9;
        else if(*ptr == 'D') HexCode=0xBA;
        else if(*ptr == 'E') HexCode=0xBB;
        else if(*ptr == 'H') HexCode=0xBC;
        else if(*ptr == 'L') HexCode=0xBD;
        else if(*ptr == 'M') HexCode=0xBE;
       else
           {
            Error();
           }
          ptr++;
    }
    else if((*ptr0 == 'C') && (*ptr1 == 'P') && (*ptr2 == 'I') && (*ptr3 == ' '))
        {
     instruction_size=2;                   
     HexCode= 0xFE;
    ptr = skip_spaces(ptr4);    
     ptr=Data_Store(ptr);
  }
    else if((*ptr0 == 'C') && (*ptr1 == 'M') && (*ptr2 == 'C') && (*ptr4 == ' '))
    {
        instruction_size=1;
         HexCode=0x3f;
         ptr=ptr4+1;
    }
    else if(*ptr0 == 'C' && *ptr1 == 'M' && *ptr2 == 'A' && *ptr3 == ' ')
    {
      instruction_size=1;
         HexCode=0x2F;
         ptr=ptr4+1;
    }
    else if((*ptr0 == 'C') && (*ptr1 == 'A') && (*ptr2 == 'L') && (*ptr3 == 'L') && (*ptr4 == ' ')){    
    HexCode = 0xCD;
    ptr = skip_spaces((ptr4+1));  
    ptr = Find_level_name_and_address(ptr);
  }
      else if(*ptr0 == 'C' && *ptr1 == 'Z' && *ptr2 == ' ')
    {
        HexCode=0xCC;
        ptr = skip_spaces((ptr3+1));   
       ptr = Find_level_name_and_address(ptr);
    }
     else if(*ptr0 == 'C' && *ptr1 == 'C' && *ptr2 == ' ')
    {
        HexCode=0xDC;
        ptr = skip_spaces(ptr);   
        ptr = Find_level_name_and_address(ptr);
    }
     else if(*ptr0 == 'C' && *ptr1 == 'P' && *ptr2 == ' ')
    {
         HexCode=0xF4;
        ptr = skip_spaces(ptr);   
        ptr = Find_level_name_and_address(ptr);
    }
     else if(*ptr0 == 'C' && *ptr1 == 'M' && *ptr2 == ' ')
    {
        HexCode=0xFC;
        ptr = skip_spaces(ptr);    
        ptr = Find_level_name_and_address(ptr);
    }
    else if(*ptr0 == 'C' && *ptr1 == 'N' && *ptr2 == 'Z' && *ptr3 == ' ')
    {
          HexCode=0xC4;
        ptr = skip_spaces(ptr);   
        ptr = Find_level_name_and_address(ptr);
    }
    else if(*ptr0 == 'C' && *ptr1 == 'N' && *ptr2 == 'C' && *ptr3 == ' ')
    {
          HexCode=0xD4;
        ptr = skip_spaces(ptr);   
        ptr = Find_level_name_and_address(ptr);
    }
    else if(*ptr0 == 'C' && *ptr1 == 'A' && *ptr2 == 'L' && *ptr3 == 'L' && *ptr4 == ' ')
    {
         HexCode=0xCD;
        ptr = skip_spaces(ptr);    
        ptr = Find_level_name_and_address(ptr);
    }
    else if(*ptr0 == 'C' && *ptr1 == 'P' && *ptr2 == 'E' && *ptr3 == ' ')
    {
         HexCode=0xEC;
        ptr = skip_spaces(ptr);   
        ptr = Find_level_name_and_address(ptr);
    }
    else if(*ptr0 == 'C' && *ptr1 == 'P' && *ptr2 == 'O' && *ptr3 == ' ')
    {
          HexCode=0xE4;
        ptr = skip_spaces(ptr);    
        ptr = Find_level_name_and_address(ptr);
    }
     Detect_Remain(ptr);
}
/*****************************************************************************************************************************************/
                          ////  Letter " E " //// 
/*****************************************************************************************************************************************/

void First_char_E(char *Instruct){
  char *ptr;
   instruction_size=1;
    update_data1(Instruct);
  if((*ptr0 == 'E') && (*ptr1 == 'I')) HexCode = 0xFB;
  ptr = ptr2;
    Detect_Remain(ptr);
}

/*****************************************************************************************************************************************/
                          ////  Letter " H " 
/*****************************************************************************************************************************************/


void First_char_H(char *Instruct){
 char *ptr;
  instruction_size=1;
    update_data1(Instruct);
  if((*ptr0 == 'H') && (*ptr1 == 'L') && (*ptr2 == 'T')) HexCode = 0x76;
  ptr = ptr3;
 Detect_Remain(ptr);
}

/*****************************************************************************************************************************************/
                          ////  Letter " N " //// 10
/*****************************************************************************************************************************************/


void First_char_N(char *Instruct){
  char *ptr;
   instruction_size=1;
    update_data1(Instruct);
  if((*ptr0 == 'N') && (*ptr1 == 'O') && (*ptr2 == 'P')) HexCode = 0x00;
  ptr = ptr3;
 Detect_Remain(ptr);
}
/*****************************************************************************************************************************************/
                          ////  Letter " D " //// 16
/*****************************************************************************************************************************************/

void First_char_D(char *Instruct)
{
    char *ptr;
    update_data1(Instruct);
    if((*ptr0 == 'D') && (*ptr1 == 'A') && (*ptr2 == 'A') && (*ptr3==' '))
    {
     instruction_size=1;
    HexCode = 0x27;
    ptr=ptr4;
  }
  else if((*ptr0 == 'D') && (*ptr1 == 'I') && (*ptr2==' ')){
     HexCode = 0xF3;
    instruction_size=1;
    ptr = ptr3;
  }
    else if(*ptr0 == 'D' && *ptr1 == 'C' && *ptr2 == 'X' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4);
        if(*ptr == 'B')  HexCode=0x0B;
        else if(*ptr == 'D')  HexCode=0x1B;
        else if(*ptr == 'H') HexCode=0x2B;
        else if(*ptr == 'S' && *(ptr+1) == 'P') HexCode=0x3B;
         else
           {
            Error();
           }
           ptr=ptr+2;
    }
    else if(*ptr0 == 'D' && *ptr1 == 'A' && *ptr2 == 'D' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4);
        if(*ptr == 'B')  HexCode=0x09;
        else if(*ptr == 'D') HexCode=0x19;
        else if(*ptr == 'H') HexCode=0x29;
        else if(*ptr == 'S' && *(ptr+1) == 'P') HexCode=0x39;
        else
           {
            Error();
           }
           ptr=ptr+2;
    }
     else if(*ptr0 == 'D' && *ptr1 == 'C' && *ptr2 == 'R' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4);
        if(*ptr == 'A') HexCode=0x3D;
        else if(*ptr == 'B') HexCode=0x05;
        else if(*ptr == 'C') HexCode=0x0D;
        else if(*ptr == 'D') HexCode=0x15;
        else if(*ptr == 'E') HexCode=0x1D;
        else if(*ptr == 'H') HexCode=0x25;
        else if(*ptr == 'L') HexCode=0x2D;
        else if(*ptr == 'M') HexCode=0x35;
       else
           {
            Error();
           }
                   ptr=ptr+2;

    }
   Detect_Remain(ptr);
}

/*****************************************************************************************************************************************/
                          ////  Letter " I " //// 12
/*****************************************************************************************************************************************/

void First_char_I(char *Instruct)
{
    char *ptr;
     update_data1(Instruct);
    if(*ptr0 == 'I' && *ptr1 == 'N' && *ptr2 == 'R' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4);
        if(*ptr == 'A') HexCode=0x3C;
        else if(*ptr == 'B') HexCode=0x04;
        else if(*ptr == 'C') HexCode=0x0C;
        else if(*ptr == 'D') HexCode=0x14;
        else if(*ptr == 'E') HexCode=0x1C;
        else if(*ptr == 'H') HexCode=0x24;
        else if(*ptr == 'L') HexCode=0x2C;
        else if(*ptr == 'M') HexCode=0x34;
         else
           {
            Error();
           }
       ptr++;

    }
    else if(*ptr0 == 'I' && *ptr1 == 'N' && *ptr2 == 'X' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4);
        if(*ptr == 'B') HexCode=0x03;
        else if(*ptr == 'D') HexCode=0x13;
        else if(*ptr == 'H') HexCode=0x23;
        else if(*ptr == 'S' && *(ptr+1) == 'P')  HexCode=0x33;
         else
           {
            Error();
           }
        ptr=ptr+2;
    }
     else if((*ptr0 == 'I') && (*ptr1 == 'N') && (*ptr2 == ' ')){
    HexCode = 0xDB;
    ptr = skip_spaces(ptr3);
    ptr=Data_Store(ptr);
  }
    Detect_Remain(ptr);
}

/*****************************************************************************************************************************************/
                          ////  Letter " J " ////
/*****************************************************************************************************************************************/

void First_char_J(char *Instruct)
{
    char *ptr,True=0;
     update_data1(Instruct);
    if(*ptr0 == 'J' && *ptr1 == 'M' && *ptr2 == 'P' && *ptr3 == ' ')
    {
        HexCode=0xC3;
        ptr = skip_spaces(ptr3);    // removing the spaces
        ptr = Find_level_name_and_address(ptr);
    }
    else if(*ptr0 == 'J' && *ptr1 == 'N' && *ptr2 == 'C' && *ptr3 == ' ')
    {
          HexCode=0xD2;
        ptr = skip_spaces(ptr3);    // removing the spaces
        ptr = Find_level_name_and_address(ptr);
    }
    else if(*ptr0 == 'J' && *ptr1 == 'N' && *ptr2 == 'Z' && *ptr3 == ' ')
    {
        HexCode=0xFA;
        ptr = skip_spaces(ptr3);    // removing the spaces
        ptr = Find_level_name_and_address(ptr);
    }
    else if(*ptr0 == 'J' && *ptr1 == 'P' && *ptr2 == 'E' && *ptr3 == ' ')
    {   HexCode=0xEA;
        ptr = skip_spaces(ptr3);    // removing the spaces
        ptr = Find_level_name_and_address(ptr);
    }
    else if(*ptr0 == 'J' && *ptr1 == 'P' && *ptr2 == 'O' && *ptr3 == ' ')
    {
        HexCode=0xE2;
        ptr = skip_spaces(ptr3);    // removing the spaces
        ptr = Find_level_name_and_address(ptr);
    }
    else if(*ptr0 == 'J' && *ptr1 == 'M' && *ptr2 == ' ')
    {
           HexCode=0xFA;
        ptr = skip_spaces(ptr2);    // removing the spaces
        ptr = Find_level_name_and_address(ptr);
    }
    else if(*ptr0 == 'J' && *ptr1 == 'C' && *ptr2 == ' ')
    {
           HexCode=0xDA;
        ptr = skip_spaces(ptr2);    // removing the spaces
        ptr = Find_level_name_and_address(ptr);
    }
     else if(*ptr0 == 'J' && *ptr1 == 'Z' && *ptr2 == ' ')
    {
           HexCode=0xCA;
        ptr = skip_spaces(ptr2);    // removing the spaces
        ptr = Find_level_name_and_address(ptr);
    }
    else if(*ptr0 == 'J' && *ptr1 == 'P' && *ptr2 == ' ')
    {
         HexCode=0xF2;
        ptr = skip_spaces(ptr2);    // removing the spaces
        ptr = Find_level_name_and_address(ptr);
    }
    else
     {
            Error();
           }
     Detect_Remain(ptr);
}

/*****************************************************************************************************************************************/
                          ////  Letter " L " ////
/*****************************************************************************************************************************************/
void First_char_L(char *Instruct)
{
    char *ptr;
    update_data1(ptr);

  if((*ptr0 == 'L') && (*ptr1 == 'D') && (*ptr2 == 'A') && (*ptr3 == ' ')){   
 instruction_size=3;
    HexCode = 0x3A;
    ptr = skip_spaces(ptr4);    // removing the spaces
    ptr = Find_address(ptr);
    ptr++;
  }
  else if((*ptr0 == 'L') && (*ptr1 == 'H') && (*ptr2 == 'L') && (*ptr3 == 'D') && (*ptr4 == ' ')){     
    instruction_size=3;
    HexCode = 0x2A;
    ptr = skip_spaces(ptr4);    // removing the spaces
    ptr = Find_address(ptr);
    ptr++;
  }
  else if((*ptr0 == 'L') && (*ptr1 == 'X') && (*ptr2 == 'I') && (*ptr3 == ' ')){                       
    ptr = skip_spaces(ptr4);    // removing the space
         if(*ptr == 'B') HexCode = 0x01;
    else if(*ptr == 'D') HexCode = 0x11;
    else if(*ptr == 'H') HexCode = 0x21;
    else if((*ptr == 'S') && (*(ptr+1) == 'P')){ HexCode = 0x31;}
    else Error();
    ptr++;
    ptr = Find_comma(ptr);
    ptr = skip_spaces(ptr+1);
    ptr = Find_address(ptr);
    ptr++;
   }
  else if((*ptr0 == 'L') && (*ptr1 == 'D') && (*ptr2 == 'A') && (*ptr3 == 'X') && (*ptr4 == ' ')){      
    ptr = skip_spaces(ptr4+1);

         if(*ptr == 'B') HexCode = 0x0A;
    else if(*ptr == 'D') HexCode = 0x1A;
    else Error();
  }
  else Error();
  Detect_Remain(ptr);
}

/*****************************************************************************************************************************************/
                          ////  Letter " R " //// 5
/*****************************************************************************************************************************************/

void First_char_R(char *Instruct)
{
    char *ptr;
    update_data1(Instruct);
    if(*ptr0 == 'R' && *ptr1 == 'S' && *ptr2 == 'T' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4);
        if(*ptr == '0') HexCode=0xC7;
        else if(*ptr == '1') HexCode=0xCF;
        else if(*ptr == '2') HexCode=0xD7;
        else if(*ptr == '3') HexCode=0xDF;
        else if(*ptr == '4') HexCode=0xE7;
        else if(*ptr == '5') HexCode=0xEF;
        else if(*ptr == '6') HexCode=0xF7;
        else if(*ptr == '7') HexCode=0xFF;
        else
           {
            Error();
           }
       ptr++;
    }
    else if(*ptr0 == 'R' && *ptr1 == 'L' && *ptr2 == 'C' && *ptr4==' ')
    {
        instruction_size=1;
        HexCode=0x07;
        ptr=ptr4+1;
    }
    else if(*ptr0 == 'R' && *ptr1 == 'R' && *ptr2 == 'C' && *ptr3==' ')
    {

          instruction_size=1;
          ptr=ptr4+1;
          HexCode=0x0f;
    }
     else if(*ptr0 == 'R' && *ptr1 == 'A' && *ptr2 == 'L' && *ptr3==' ')
    {
       instruction_size=1;
          ptr=ptr4+1;
          HexCode=0x17;
    }
     else if(*ptr0 == 'R' && *ptr1 == 'A' && *ptr2 == 'R' && *ptr3 == ' ')
    {
       instruction_size=1;
           ptr=ptr4+1;
          HexCode=0x1F;
    }
     else if(*ptr0 == 'R' && *ptr1 == 'E' && *ptr2 == 'T'&& *ptr3==' ')
    {
        instruction_size=1;
           ptr=ptr4+1;
          HexCode=0xC9;
    }
     else if(*ptr0 == 'R' && *ptr1 == 'I' && *ptr2 == 'M' && *ptr3 == ' ')
    {
       instruction_size=1;
          ptr=ptr4+1;
          HexCode=0x20;
    }
     else if(*ptr0 == 'R' && *ptr1 == 'N' && *ptr2 == 'C' && *ptr3==' ')
    {
        instruction_size=1;
         ptr=ptr4+1;
          HexCode=0xD0;
    }
     else if(*ptr0 == 'R' && *ptr1 == 'N' && *ptr2 == 'Z' && *ptr3==' ')
    {
        instruction_size=1;
         ptr=ptr4+1;
          HexCode=0xC0;
    }
     else if(*ptr0 == 'R' && *ptr1 == 'P' && *ptr2 == 'E' && *ptr3 == ' ')
    {
      instruction_size=1;
           ptr=ptr4+1;
          HexCode=0xE8;
    }
     else if(*ptr0 == 'R' && *ptr1 == 'P' && *ptr2 == 'O'&& *ptr3 == ' ')
    {
       instruction_size=1;
          ptr=ptr4+1;
          HexCode=0xE0;
    }
     else if(*ptr0 == 'R' && *ptr1 == 'C' && *ptr2 == ' ')
    {
       instruction_size=1;
           ptr=ptr3+1;
          HexCode=0xD8;
    }
     else if(*ptr0 == 'R' && *ptr1 == 'P' && *ptr2 == ' ')
    {
      instruction_size=1;
          ptr=ptr3+1;
          HexCode=0xF0;
    }
     else
           {
            Error();
           }
           Detect_Remain(ptr);
}

/*****************************************************************************************************************************************/
                          ////  Letter " S " //// 17
/*****************************************************************************************************************************************/

void First_char_S(char *Instruct)
{
    char *ptr;
    update_data1(Instruct);
    if(*ptr0 == 'S' && *ptr1 == 'U' && *ptr2 == 'B' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr3);
        if(*ptr == 'A') HexCode=0x97;
        else if(*ptr == 'B') HexCode=0x90;
        else if(*ptr == 'C') HexCode=0x91;
        else if(*ptr== 'D') HexCode=0x92;
        else if(*ptr == 'E') HexCode=0x93;
        else if(*ptr == 'H') HexCode=0x94;
        else if(*ptr == 'L') HexCode=0x95;
        else if(*ptr == 'M') HexCode=0x96;
      else
           {
            Error();
           }
           ptr++;
    }
    else if(*ptr0 == 'S' && *ptr1 == 'B' && *ptr2 == 'B' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr3);
        if(*ptr == 'A') HexCode=0x8F;
        else if(*ptr == 'B') HexCode=0x98;
        else if(*ptr == 'C') HexCode=0x99;
        else if(*ptr == 'D') HexCode=0x9A;
        else if(*ptr == 'E') HexCode=0x9B;
        else if(*ptr == 'H') HexCode=0x9C;
        else if(*ptr == 'L') HexCode=0x9D;
        else if(*ptr == 'M') HexCode=0x9E;
      else
           {
            Error();
           }
        ptr++;
    }
    else if(*ptr0 == 'S' && *ptr1 == 'T' && *ptr2 == 'C' && *ptr3 == ' ')
    {
       instruction_size=1;
          ptr=ptr3;
          HexCode=0x37;
    }
    else if(*ptr0 == 'S' && *ptr1 == 'I' && *ptr2 == 'M' && *ptr3 == ' ')
    {
       instruction_size=1;
           ptr=ptr3;
          HexCode=0x30;
    }
    else if(*ptr0 == 'S' && *ptr1 == 'P' && *ptr2 == 'H' && *ptr3 == 'L' && *ptr4 == ' ')
    {
       instruction_size=1;
           ptr=ptr4;
          HexCode=0xF9;
    }
     else if(*ptr0 == 'S' && *ptr1 == 'U' && *ptr2 == 'I' && *ptr3 == ' ')
    {
            instruction_size=2;
             HexCode = 0xD6;
    ptr = skip_spaces(ptr3);    // removing the spaces
     ptr=Data_Store(ptr);
    }
     else if(*ptr0 == 'S' && *ptr1 == 'B' && *ptr2 == 'I' && *ptr3 == ' ')
    {
      instruction_size=2;
             HexCode = 0xDE;
            ptr = skip_spaces(ptr3);    // removing the spaces
              ptr=Data_Store(ptr);
    }
    else if((*ptr0 == 'S') && (*ptr1 == 'H') && (*ptr2 == 'L') && (*ptr3 == 'D') && (*ptr4 == ' ')){     //////////// SHLD //////////////////
    HexCode = 0x22;
    ptr = skip_spaces(ptr4);    // removing the spaces
    ptr = Find_address(ptr);
  }
  else if((*ptr0 == 'S') && (*ptr1 == 'T') && (*ptr2 == 'A') && (*ptr3 == ' ')){                       //////////// STA //////////////////
    HexCode = 0x32;
    ptr = skip_spaces(ptr3);    // removing the spaces
    ptr = Find_address(ptr);
  }
     else
           {
            Error();
           }
           Detect_Remain(ptr);
}

/*****************************************************************************************************************************************/
                          ////  Letter " X " //// 8
/*****************************************************************************************************************************************/

void First_char_X(char *Instruct)
{
    char *ptr;
    update_data1(Instruct);
    if(*ptr0 == 'X' && *ptr1 == 'R' && *ptr2 == 'A' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4);
        if(*ptr == 'A') HexCode=0xA7;
        else if(*ptr == 'B') HexCode=0xA8;
        else if(*ptr == 'C') HexCode=0xA9;
        else if(*ptr == 'D') HexCode=0xAA;
        else if(*ptr == 'E') HexCode=0xAB;
        else if(*ptr == 'H') HexCode=0xAC;
        else if(*ptr == 'L') HexCode=0xAD;
        else if(*ptr == 'M') HexCode=0xAE;
          else
           {
            Error();
           }
        ptr++;
    }
     else if(*ptr0 == 'X' && *ptr1 == 'R' && *ptr2 == 'I' && *ptr3 == ' ')
    {
        instruction_size=2;
            HexCode = 0xDE;
            ptr = skip_spaces(ptr4+1);    // removing the spaces
              ptr=Data_Store(ptr);
    }
    else if(*ptr0 == 'X' && *ptr1 == 'T' && *ptr2 == 'H' && *ptr3 == 'L' && *ptr4 == 'c')
    {
       instruction_size=2;
           HexCode = 0xE3;
            ptr = skip_spaces(ptr4+1);    // removing the spaces
             ptr=Data_Store(ptr);
    }
     else if(*ptr0 == 'X' && *ptr1 == 'C' && *ptr2 == 'H' && *ptr3 == 'G' && *ptr4 == 'c')
    {
       instruction_size=2;
           HexCode = 0xEB;
            ptr = skip_spaces(ptr4+1);    // removing the spaces
              ptr=Data_Store(ptr);
    }
    else
           {
            Error();
           }
           Detect_Remain(ptr);
}
/*****************************************************************************************************************************************/
                          ////  Letter " P " ////
/*****************************************************************************************************************************************/

void First_char_P(char *Instruct)
{
    char *ptr;
    update_data1(Instruct);
    if((*ptr0 == 'P') && (*ptr1 == 'C') && (*ptr2 == 'H') && (*ptr3 == 'L')){                           
    HexCode = 0xE9;
    ptr=ptr4;
  }
   else if(*ptr0 == 'P' && *ptr1 == 'O' && *ptr2 == 'P' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4);
        if(*ptr == 'B') HexCode=0xC1;
        else if(*ptr == 'D') HexCode=0xD1;
        else if(*ptr == 'H') HexCode=0xE1;
        else if(*ptr == 'E' && *(ptr+1) == 'P' && *(ptr+2) == 'S' && *(ptr+3) == 'W' ) HexCode=0xF1;
           else
           {
            Error();
           }
        ptr++;
    }
    else if(*ptr0 == 'P' && *ptr1 == 'U' && *ptr2 == 'S' && *ptr3 == 'H' && *ptr4 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4+1);
        if(*ptr == 'B') HexCode=0xC5;
        else if(*ptr == 'D') HexCode=0xD5;
        else if(*ptr == 'H') HexCode=0xE5;
        else if(*ptr == 'E' && *(ptr+1) == 'P' && *(ptr+2) == 'S' && *(ptr+3) == 'W' ) HexCode=0xF5;
           else Error();
        ptr=(ptr+4);
    }
           else Error();
           Detect_Remain(ptr);
}

/*****************************************************************************************************************************************/
                          ////  Letter " O " //// 8
/*****************************************************************************************************************************************/
void First_char_O(char *Instruct)
{
    char *ptr;
    update_data1(Instruct);
    if(*ptr0 == 'O' && *ptr1 == 'R' && *ptr2 == 'A' && *ptr3 == ' ')
    {
        instruction_size=1;
        ptr=skip_spaces(ptr4);
        if(*ptr == 'A') HexCode=0xB7;
        else if(*ptr == 'B') HexCode=0xB0;
        else if(*ptr == 'C') HexCode=0xB1;
        else if(*ptr == 'D') HexCode=0xB2;
        else if(*ptr == 'E') HexCode=0xB3;
        else if(*ptr == 'H') HexCode=0xB4;
        else if(*ptr == 'L') HexCode=0xB5;
        else if(*ptr == 'M') HexCode=0xB6;
           else
           {
            Error();
           }
        ptr++;
    }
    else if(*ptr0 == 'O' && *ptr1 == 'R' && *ptr2 == 'I' && *ptr3 == ' ')
    {
       instruction_size=2;
          HexCode = 0xF6;
            ptr = skip_spaces(ptr4);    // removing the spaces
             ptr=Data_Store(ptr);
    }

       else
           {
            Error();
           }
           Detect_Remain(ptr);
}
void main()
{
    char Instruct[100];

/****************************************************************************************/

    FILE *read=NULL,*write=NULL;
    read=fopen("abc.asm","r");

   line_number=start_line_number;
   memory_address=Starting_Address;
char True=0,*copyptr,i=0,j=0;

  while (fgets(Instruct, sizeof(Instruct), read) != NULL){
         instruction_size = detect_levels(Instruct);
          line_number++;
         memory_address=memory_address+instruction_size;
         i++;
         j++;
         if((!instruction_size) || (error_flag)) goto End;
    }
    fclose(read);

/*******************************************************************************************************/

     line_number=start_line_number;
   memory_address=Starting_Address;
   instruction_size=0;
    read=fopen("abc.asm","r");
    write=fopen("abc.bin","w");

  while (fgets(Instruct, sizeof(Instruct), read) != NULL){
           Instruction_Line(Instruct);
          if(!(instruction_size) || (error_flag)) goto End;
         if(comment_flag){ comment_flag = 0; goto skip;}

         if(instruction_size==1)
         {
         fprintf(write,"%X\n",HexCode);
         }
         else if(instruction_size==2)
         {
             fprintf(write,"%X\n",HexCode);
           fprintf(write,"%s\n",data);
         }
         else if(instruction_size==3)
         {
             fprintf(write,"%X\n",HexCode);
            fprintf(write,"%s\n",LSB_byte_address);
            fprintf(write,"%s\n",MSB_byte_address);
         }
         else
         {
             Error();
         }
  skip:       line_number++;
    }
    printf("Successfully completed");

End:    fclose(write);
        fclose(read);
}
