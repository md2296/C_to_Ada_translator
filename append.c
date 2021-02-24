/* Source: https://www.tutorialspoint.com/learn_c_by_examples/program_to_append_file_in_c.htm */
#include <stdio.h>
 
int main()
{
   FILE *fp;
   char ch;
   char *filename = "program.txt";
   char *content = "This text is appeneded later to the file, using C programming.";

   /*  open for writing */
   fp = fopen(filename, "r");
   
   printf("\nContents of %s  -\n\n", filename);
   
   while ((ch = fgetc(fp) )!= EOF)
   {
      printf ("%c", ch);
   }

   fclose(fp);
   
   fp = fopen(filename, "a");

   /* Write content to file */
   fprintf(fp, "%s\n", content);

   fclose(fp);

   fp = fopen(filename, "r");

   printf("\nContents of %s  -\n", filename);
   
   while ((ch = fgetc(fp) )!= EOF)
   {
      printf ("%c", ch);
   }

   fclose(fp);

   return 0;
}
