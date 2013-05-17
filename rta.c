#import <stdio.h>
#import <strings.h>

int rta(char roman); // roman digit to arabic digit

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("usage: rta [IVXLCDM]\r\n");
        return 0;
    }
    
    int psum = 0, tsum = 0; //partial sum and total sum
    int i,n = strlen(argv[1]);
    char lastletter = 0;
    
    for (i=0;i<n;i++)
    {
        int letter_value = rta(argv[1][i]);
        if (lastletter != argv[1][i]) {
            if (rta(lastletter) > letter_value) {
                tsum += psum;
            } else {
                tsum -= psum;
            }
            psum = 0;
        }
        psum += letter_value;
        lastletter = argv[1][i];
    }
    tsum += psum;
    
    printf("Roman: %s\r\nArabic: %d\r\n",argv[1],tsum);
    return 0;
}

int rta(char roman)
{
	
    switch (toupper(roman))
    {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
             return 500;
        case 'M':
             return 1000;
    }
    return 0;
}