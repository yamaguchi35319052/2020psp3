#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int start = 0;
    int pos = 0;
    int text_len;
    int key_len;

    text_len = strlen(text);
    key_len = strlen(key);

    for(start; start+key_len < text_len; start++)
    {
        for(pos; pos < key_len; pos++)
        {
            if(text[start+pos] == key[pos])
            {
                if(pos+1 == key_len)
                {
                    return &text[start];
                }
            }
            else
            {
                break;
            }
            
        }
    }
        return NULL;
}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    char* c;
    int index;
    int key_index;
    int text_len, key_len;
    int table[256];

    text_len = strlen(text);
    key_len = strlen(key);

    for(int pos = 0;pos<256;pos++)
    {
        table[pos] = key_len;
    }
    for(int pos=0;key[pos] !=NULL; pos++)
    {
        table[key[pos]] = (key_len-1)-pos;
    }

    key_index = key_len-1;
    while(text[key_index] !=text_len)
    {
        c = &text[key_index-(key_len-1)];
        for(index = 0;key[index] !=0; index++)
        {
            if(text[key_index-index] != key[(key_len-1)-index])
            {
                if(table[text[key_index-index]] >index)
                {
                    key_index += (int)table[text[key_index - index]] - index;
                }
                else
                {
                    key_index++;
                }
                c = NULL;
                break;
            }
        }
        if(c !=NULL)
        {
            return c;
        }
    }
    return NULL;
}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}