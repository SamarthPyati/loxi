#include <stdio.h>

#define SV_STR_IMPLEMENTATION
#include "sv_str.h"

// Objective: Lex all the tokens in the below string in upper case
const char *text = "This young gentlewoman had a father,--O, that                   \
'had'! how sad a passage 'tis!--whose skill was                                     \
almost as great as his honesty; had it stretched so                                 \
far, would have made nature immortal, and death                                     \
should have play for lack of work. Would, for the                                   \
king's sake, he were living! I think it would be                                    \
the death of the king's disease.";


int main(void) {
    StringView s = sv_from_cstr("Samarth Pyati");
    printf(SV_Fmt"\n", s);


    // s.data[s.count] = '\0';

    // char *token;
    // while ((token = strsep(s.data, " ")) != NULL) {
    //     if (token) {
    //         printf("Token: %s\n", token);
    //     }
    // }

    return 0; 
}