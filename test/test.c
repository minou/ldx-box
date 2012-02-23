#include <stdio.h>

int main(int argc, char ** argv)
{
    FILE * file;
    int result;
    printf("Test ouverture du fichier /etc/passwd, mode r\n");
    file = fopen("/etc/passwd", "r");
    if (file == NULL) {
        printf("Ouverture refusée\n");
    }
    printf("Test déplacement du fichier /etc/passwd dans /tmp/passwd\n");
    result = rename("/etc/passwd", "tmp/passwd");
    if (result != 0){
        printf("Déplacement refusé\n");
    }
    printf("Test supression du fichier /etc/passwd\n");
    result = remove("/etc/passwd");
    if (result != 0){
        printf("Supression refusée\n");
    }

    printf("Test ouverture du fichier /tmp/toto, mode w\n");
    file = fopen("/tmp/toto", "w");
    if (file != NULL){
        printf("Ouverture réussie\n");
        fclose(file);
    }
    printf("Test supression du fichier /tmp/toto\n");
    result = remove("/tmp/toto");
    if (result == 0){
        printf("Supression réussie\n");
    }
    return 0;
}
