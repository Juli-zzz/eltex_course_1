#include <stdio.h> 

void positive_integer(int firstNumber)
{
    unsigned int s_bit, com, bin;
    int i = 0;
    
    s_bit = sizeof(firstNumber)*8;
    com = 1<<(s_bit - 1);

    while ((com & firstNumber) == 0 && com != 0)
    {
        com >>= 1;
    }   

    while(com != 0)
    {   
        bin = ("%u",(com & firstNumber) ? 1 : 0 );
        com >>= 1;
        printf("%u", bin); 
        if (bin == 1)
            {
                i++;
            }
    }
    printf("\nКоличество единиц в двоичном представлении целого положительного числа:\n");        
    printf("%d", i);
}

void negative_integer(int firstNumber)
{
    unsigned int s_bit, com;
    
    unsigned int invert_number = firstNumber * -1; 

    int new_number = (~invert_number) + 1;

    s_bit = sizeof(new_number)*8;
    com = 1<<(s_bit - 1); 
    for (int i = 0; i < s_bit; i++)
    {   
        printf("%u",(com & new_number) ? 1 : 0 );
        com >>= 1; 
    }

}

void changeThirdByte(int firstNumber)
{
    int secondNumber;
    unsigned int s_bit, com, clear_3byte;

    printf("Enter second number 0 to 255\n"); //в 1байт - 8бит max что можно записать 11111111 - 255
    scanf("%d", &secondNumber);

    while ((secondNumber < 0) || (secondNumber > 255))
    {
      printf("Erorr!!! Enter number from the range\n");
      printf("Enter second number 0 to 255\n");
      scanf("%d", &secondNumber);
    }

    s_bit = sizeof(firstNumber)*8;  //вывод первого числа
    com = 1<<(s_bit - 1);
    for (int i = 0; i < s_bit; i++)
    {   
        printf("%u",(com & firstNumber) ? 1 : 0 );
        com >>= 1; 
    }
    printf("\n");

    s_bit = sizeof(firstNumber)*8;  //вывод второго числа
    com = 1<<(s_bit - 1);
    for (int i = 0; i < s_bit; i++)
    {   
        printf("%u",(com & secondNumber) ? 1 : 0 );
        com >>= 1; 
    }
    printf("\n");

    unsigned int clear = ~(255 << 16); 
    unsigned int second = (secondNumber & 255) << 16; 
    
    int res = (firstNumber & clear) | second;

    s_bit = sizeof(firstNumber)*8;  //вывод измененного числа
    com = 1<<(s_bit - 1);
    for(int i = 0; i < s_bit; i++)
    {
        printf("%u",(res & com) ? 1 : 0 );
        com >>= 1;
    }
    printf("\n");
       
}


int main() 
{
    int firstNumber;

    printf("Enter positive or negative integer:\n");

    if (scanf("%d",&firstNumber) !=1)
    {
        printf("Error!\n");  
        return 0;      
    }

    int chek = getchar();

    if ((chek) == '.')
    {
        printf("Error! This is not an integer\n"); 
        return 0;
    } else if ((chek != '\n') && (chek != EOF))
        {
        printf("Error!!!\n");
        return 0;
        }

    if (firstNumber < 0)
    {
        printf("Binary negativ integer\n");
        negative_integer(firstNumber);
        printf("\n");
        
    }
    if (firstNumber > 0)
    {
        printf("Binary positive intrger:\n");   
        positive_integer(firstNumber);
        printf("\n");
        changeThirdByte(firstNumber);
    }   
    if (firstNumber==0)
    {
        printf("Binary interger 0\n");
    } 
    


    return 0;
} 
