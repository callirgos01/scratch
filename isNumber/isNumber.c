#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>     /* atoi */

//ilegal sequences.
//e.
//ee
//--
//++

bool isNumber(char* s)
{  
    float result = 0;
    printf("input %s\r\n", s);
    
    if( strstr(s, "ee") != 0 )
    {
        return false;
    } if( strstr(s, ".e") != 0 )
    {
        return false;
    }
    if( strstr(s, ".+") != 0 )
    {
        return false;
    }
    if( strstr(s, ".-") != 0 )
    {
        return false;
    }

    char *toIter = s;
    printf("%u %u\r\n", (unsigned int)s, (unsigned int) toIter);
    bool eSeen = false;
    
    //detect point after e
    while(*toIter)
    {
        if(*toIter == 'e') {
            eSeen = true;
        }
        else if( (*toIter == '.') && (eSeen == true) ) {
            printf("char to check %u\r\n", *toIter);
            return false;
        }
        toIter++;
    }

    while(*s == '0')
    {
        if(*(s+1) == 0)
        {
            return true;
        }
        s++;
    }
    
    result = atof(s);
    printf(" %s => %f\r\n", s, result);
    return result != 0;
}

int main( void )
{   
    //"0" => true
    assert(isNumber("0e") == false);
    assert(isNumber("e2") == false);
    assert(isNumber("e") == false);
    assert(isNumber("1e2") == true);
    assert(isNumber("6ee69") == false);
    assert(isNumber("+.8") == true);
    assert(isNumber("+1") == true);
    assert(isNumber("1.+2.") == false);
    assert(isNumber("+.1") == true);
    assert(isNumber("+0.1") == true);
    assert(isNumber("++") == false);
    assert(isNumber("+e+") == false);
    assert(isNumber("+12.") == true);
    assert(isNumber(".+4") == false);
    assert(isNumber("6e6.5") == false);
    assert(isNumber("46.e3") == false);
    assert(isNumber("-1") == true);
    assert(isNumber("1.-2.") == false);
    assert(isNumber("-.1") == true);
    assert(isNumber("-0.1") == true);
    assert(isNumber("--") == false);
    assert(isNumber("-e-") == false);
    assert(isNumber("-12.") == true);
    assert(isNumber(".-4") == false);
    assert(isNumber("6e6.5") == false);


    //" 0.1 " => true
    assert(isNumber(".") == false);
    assert(isNumber("..") == false);
    assert(isNumber(".3") == true);
    assert(isNumber("3.") == true);
    assert(isNumber("e") == false);
    assert(isNumber("2e") == false);
    //"abc" => false
    assert(isNumber("abc") == false);
    //"1 a" => false
    assert(isNumber("1 a") == false);
    //"2e10" => true
    assert(isNumber("2e10") == true);

    printf("All Tests Pass!!");

}