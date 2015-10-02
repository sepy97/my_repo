#include <stdio.h>
#include <string.h>
#include <assert.h>

char* mystrstr (char* str, const char* ctrl);

int main()
{
    char* str     = "This is testing string to test string function strstr";
    char* ctrlout = strstr   (str, "strt");
    char* out     = mystrstr (str, "strt");
    
    if (ctrlout == out) printf ("GOOD \n");
    else                printf ("VERY BAD\n");
}

char* mystrstr (char* str, const char* ctrl)
{
    assert (str != NULL);
    assert (ctrl != NULL);
    for (int i = 0; i < strlen (str); i++)
    {
        assert (i < strlen (str));
        int j = 0;
        if (str[i] == ctrl[j])
        {
            int test = 0;
            for (int k = i + 1, j = 1; j < strlen (ctrl); j++, k++)
            {
                assert (j < strlen (ctrl));
                if (str[k] != ctrl[j])
                {
                    test = 1;
                    break;
                }
                
            }
            if (test == 0)
            {
                return &str[i];
            }
        }
    }
    return NULL;
}