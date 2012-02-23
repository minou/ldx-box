#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    FILE * file;
    char *src, *dest, *mode;
    int result;
    src = "/etc/passwd";
    dest = "/tmp/passwd";
    mode = "r";

    printf("Test ouverture du fichier %s, mode %s\n", src, mode);
    file = fopen(src, mode);
    if (file == NULL)
        printf("Ouverture refusée\n");
    printf("Test déplacement du fichier %s dans %s\n", src, dest);
    result = rename(src, dest);
    if (result != 0)
        printf("Déplacement refusé\n");
    printf("Test supression du fichier %s\n", src);
    result = remove(src);
    if (result != 0)
        printf("Supression refusée\n");

    src = "/tmp/toto";
    dest = "/tmp/titi";
    mode = "w";
    printf("Test ouverture du fichier %s, mode %s\n", src, mode);
    file = fopen(src, mode);
    if (file != NULL){
        printf("Ouverture réussie\n");
        fclose(file);
    }
    system("echo 'Hello Word' > /tmp/tata");
    src = "/tmp/tata";
    printf("Test déplacement du fichier %s dans %s\n", src, dest);
    result = rename("/tmp/tata", dest);
    if (result == 0)
        printf("Déplacement réussi\n");
    printf("Test supression du fichier %s\n", dest);
    result = remove(dest);
    if (result == 0)
        printf("Supression réussie\n");
    return 0;
}
