/* Source: https://www.tutorialspoint.com/learn_c_by_examples/program_to_append_file_in_c.htm, https://stackoverflow.com/questions/16400886/reading-from-a-file-word-by-word */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void read_words(FILE *f);
void add_words(char *output_filename,  FILE *f);
 
int main(void)
{
   FILE *fp;
   char *input_filename = "from_c_program.c";
   char *output_filename = "main.adb";

   /*  open for reading */
   fp = fopen(input_filename, "r");
   printf("\nContents of %s  -\n\n", input_filename);   
   read_words(fp);
   fclose(fp);

   fp = fopen(input_filename, "r");
   add_words(output_filename, fp);
   fclose(fp);
  
   fp = fopen(output_filename, "r");
   printf("\nContents of %s  -\n", output_filename);
   read_words(fp);
   fclose(fp);

   return 0;
}

void read_words(FILE *f) {
    char x[1024];
    /* assumes no word exceeds length of 1023 */
    while (fscanf(f, " %1023s", x) == 1) {
        puts(x);
    }
}

void add_words(char *output_filename,  FILE *f) {
    int i = 0;
    int j = 0;
    int parenthesis_counter = 0;
    FILE *fp;
    char x[1024];
    char str_dummy_src[1024];
    char str_dummy_dest[1024];
    char *content = "none";
    char *content_buffer = "none";
    char *buffer_used = "false";
    char *end_command = "false";
    char *if_flag = "none";
    char *type_flag = "none";
    char *type_flag2 = "first_time";
    typedef struct node {
        char *buffer;
        struct node *next;
        struct node *prev;
    } n;

    n *endings = NULL;
    endings = (n *)malloc(sizeof(n));
    
    fp = fopen(output_filename, "w");

    /* assumes no word exceeds length of 1023 */
    while (fscanf(f, " %1023s", x) == 1) {
	if(!(strcmp(type_flag2, "else"))) {
	    if(!(strcmp(x, "if")) || !(strcmp(x, "if("))) {	
	    	content = "els";
            	/* Write content to file */
            	fprintf(fp, "%s", content);
	    } else {
 	    	content = "else";
            	/* Write content to file */
            	fprintf(fp, "%s\n", content);
	    }
	    type_flag2 = "none";
	}
	if(!(strcmp(x, "else"))) {
	    if_flag = "in_if";
	    endings = endings->prev;
	    free(endings->next);
	}
	if(!(strcmp(if_flag, "end_bracket"))) {
	    content = endings->prev->buffer;
	    /* Write content to file */
            fprintf(fp, "%s\n", content);
	    endings = endings->prev;
	    free(endings->next);
	    if_flag = "none";
	}
	if(!(strcmp(x, "#include"))) {
            content = "with ";
            /* Write content to file */
            fprintf(fp, "%s", content);
        } else if(!(strcmp(x, "<stdio.h>"))) {
            content = "Ada.Text_IO; use Ada.Text_IO;";
            /* Write content to file */
            fprintf(fp, "%s\n", content);
        } else if(!(strcmp(x, "int"))) {
	    content_buffer = " : Integer";
	    type_flag = "func_or_var_int";
	} else if(!(strcmp(type_flag, "func_or_var_int"))) {
	    if(!(strcmp(x, "main()")) || !(strcmp(x, "main(void)")) || !(strcmp(x, "main"))) {
                content = "procedure main is ";
                /* Write content to file */
                fprintf(fp, "%s\n", content);
                endings->buffer = "end main;";
		endings->next = (n *)malloc(sizeof(n));
		endings->next->prev = endings;
		endings = endings->next;
		endings->next = NULL;
		type_flag = "read_main";
            } else {
		content = x; 
	        fprintf(fp, "%s", content);
		type_flag2 = "func_or_var";
		type_flag = "read_main";
	    }
	} else if(!(strcmp(x, "printf(\"\\n\");"))) {
	    if(!(strcmp(type_flag2, "first_time"))) {
		content = "begin";
	        /* Write content to file */
                fprintf(fp, "%s\n", content);
		type_flag2 = "not_first_time";
	    }
            content = "New_Line;";
            /* Write content to file */
            fprintf(fp, "%s\n", content);
	} else if(!(strcmp(x, "while")) || !(strcmp(x, "while("))) {	
	    if(!(strcmp(type_flag2, "first_time"))) {
		content = "begin";
	        /* Write content to file */
                fprintf(fp, "%s\n", content);
		type_flag2 = "not_first_time";
	    }
	    type_flag2 = "while";
	    content = "while "; 
	    fprintf(fp, "%s", content);
	} else if(!(strcmp(x, "if")) || !(strcmp(x, "if("))) {	
	    if(!(strcmp(type_flag2, "first_time"))) {
		content = "begin";
	        /* Write content to file */
                fprintf(fp, "%s\n", content);
		type_flag2 = "not_first_time";
	    }
	    if_flag = "in_if";
	    content = "if "; 
	    fprintf(fp, "%s", content);
	} else if(!(strcmp(x, "else"))) {	
	    if_flag = "in_if";
	    type_flag2 = "else";
	} else if(!(strcmp(x, "%d"))) {	
	    content = "\" & Integer'Image(";
	    /* Write content to file */
            fprintf(fp, "%s", content);

	} else if(!(strcmp(x, "{"))) {	
	    if(!(strcmp(type_flag2, "while"))) {
		type_flag2 = "post_while";
                endings->buffer = "end loop;";
		endings->next = (n *)malloc(sizeof(n));
		endings->next->prev = endings;
		endings = endings->next;
		endings->next = NULL;
	    } else if(!(strcmp(if_flag, "in_if"))) {
		if_flag = "post_bracket";
                endings->buffer = "end if;";
		endings->next = (n *)malloc(sizeof(n));
		endings->next->prev = endings;
		endings = endings->next;
		endings->next = NULL;
	    } 
	    if(!(strcmp(type_flag, "read_main"))) {
	        continue;
	    }
	} else if(!(strcmp(x, "}"))) {
	    if(!(strcmp(if_flag, "post_bracket"))) {
		if_flag = "end_bracket";
	    } else {
	        content = endings->prev->buffer;
	        /* Write content to file */
                fprintf(fp, "%s\n", content);
	        endings = endings->prev;
	        free(endings->next);
	    }
	} else if(!(strcmp(x, "return"))) {
	    if(!(strcmp(type_flag, "read_main"))) {
	        type_flag = "read_main_return";
	    }
	} else if((!(strcmp(x, "0;")) || !(strcmp(x, "EXIT_SUCCESS;"))) && (!(strcmp(type_flag, "read_main_return")))) {
	    content = "";
	    /* Write content to file */
            fprintf(fp, "%s\n", content);
	} else if(strstr(type_flag2, "printf%d")) {
	    content = strtok(x, ")");
	    fprintf(fp, "%s", content);
	    content = ") & \"";
	    fprintf(fp, "%s", content);
	    type_flag2 = "not_first_time";
	    for(i = 0; str_dummy_dest[i] != '\0'; i++) {
		/* Write content to file */
                fprintf(fp, "%c", str_dummy_dest[i]);
	    }
	    content = "\");";
	    fprintf(fp, "%s\n", content);
	    if(!strcmp(if_flag, "end_if")) {
	        content = endings->prev->buffer;
	        /* Write content to file */
                fprintf(fp, "%s\n", content);
	        endings = endings->prev;
	        free(endings->next);
		if_flag = "none";
	    }
	} else if(strstr(type_flag2, "printf")) {
	    if(strstr(x, "\",")) {
		content_buffer = strtok(x, ",");;
		strcpy(str_dummy_src, content_buffer);
		strcpy(str_dummy_dest, ") & \"");
		strcat(str_dummy_dest, str_dummy_src);
		type_flag2 = "printf_var";
	    } else if(!(strcmp(type_flag2, "printf_var"))) {
		content_buffer = x;
		strcpy(str_dummy_src, content_buffer);
		/* strtok manipulates x */
		content = strtok(x, ")");
		fprintf(fp, "%s", content);
		content = str_dummy_dest;
		fprintf(fp, "%s", content);
		if(strstr(str_dummy_src, ")")) {
		    content = ")";
		    fprintf(fp, "%s", content);
		    if(strstr(str_dummy_src, ";")) {
		        content = ";";
		        fprintf(fp, "%s\n", content);
			type_flag2 = "not_first_time";
			if(!strcmp(if_flag, "end_if")) {
		            content = endings->prev->buffer;
	        	    /* Write content to file */
                    	    fprintf(fp, "%s\n", content);
	            	    endings = endings->prev;
	            	    free(endings->next);
		    	    if_flag = "none";
			}
		    }
		}
	    } else {
		content = x; 
	        fprintf(fp, "%s", content);
	    }
	} else if(strstr(x, "printf")) {
	    if(!(strcmp(type_flag2, "first_time"))) {
		content = "begin";
	        /* Write content to file */
                fprintf(fp, "%s\n", content);
		type_flag2 = "not_first_time";
	    }
	    strcpy(str_dummy_src, "");
	    strcpy(str_dummy_dest, "");
	    if(!strcmp(if_flag, "in_if")) {
                endings->buffer = "end if;";
		endings->next = (n *)malloc(sizeof(n));
		endings->next->prev = endings;
		endings = endings->next;
		endings->next = NULL;
		if_flag = "end_if";
	    }
	    if(strstr(x, ");"))
		end_command = "true";
	    type_flag2 = "printf";
	    content = "Put_Line(";
	    /* Write content to file */
            fprintf(fp, "%s", content);
	    content = strtok(x, "\"");
	    content = strtok(NULL, "\"");
	    strcpy(str_dummy_src, content);
	    /* Write content to file */
            fprintf(fp, "%s", "\"");
	    for(i = 0; str_dummy_src[i] != '\0'; i++) {
		if(str_dummy_src[i] == '%') type_flag2 = "printf%";
		else if(!(strcmp(type_flag2, "printf%"))) { 
		    if(str_dummy_src[i] == 'd') {
			type_flag2 = "printf%d";
			content = "\" & Integer'Image(";
	    		/* Write content to file */
            		fprintf(fp, "%s", content);			
		    }
		} else if(!(strcmp(type_flag2, "printf%d"))) { 
		    for(j = 0; str_dummy_src[i] != '\0'; i++, j++)
			str_dummy_dest[j] = str_dummy_src[i]; 
		    str_dummy_dest[j] = '\0';
		    break;
		} else {
	            /* Write content to file */
                    fprintf(fp, "%c", str_dummy_src[i]);
		}
	    }
	    if(!(strcmp(end_command, "true"))) {
		content = "\");";
		fprintf(fp, "%s\n", content);
		type_flag2 = "not_first_time";
		end_command = "false";
		if(!strcmp(if_flag, "end_if")) {
	            content = endings->prev->buffer;
	            /* Write content to file */
                    fprintf(fp, "%s\n", content);
	            endings = endings->prev;
	            free(endings->next);
		    if_flag = "none";
		}
	    }
    	    //do { 
	    //    /* Write content to file */
            //    fprintf(fp, "\"%s", content);
	    //    content = strtok(NULL, ",");
	    //} while(content != NULL); */
	} else if(!(strcmp(x, "=")) && (strcmp(type_flag2, "func_or_var"))) {
	    content = " := ";
	    fprintf(fp, "%s", content);
	} else if(!(strcmp(x, "!"))) {
	    content = " not ";
	    fprintf(fp, "%s", content);
	} else if(!(strcmp(x, "%"))) {
	    content = " mod ";
	    fprintf(fp, "%s", content);
	} else if(!(strcmp(x, "!="))) {
	    content = " /= ";
	    fprintf(fp, "%s", content);
	} else if(!(strcmp(x, "=="))) {
	    content = " = ";
	    fprintf(fp, "%s", content);
	} else if(!(strcmp(x, "("))) {
	    if(parenthesis_counter > 0) {
	        content = "(";
	        fprintf(fp, "%s", content);
	    }
	    parenthesis_counter++;
	} else if(!(strcmp(x, ")"))) {
	    if(parenthesis_counter <= 1) {
	        if(!strcmp(type_flag2, "while")) {
	            content = " loop";
		    fprintf(fp, "%s\n", content);
	        } else if(!strcmp(if_flag, "in_if")) {
	            content = " then";
		    fprintf(fp, "%s\n", content);
	        }
	    } else {
	        content = ")";
	        fprintf(fp, "%s", content);
	    }
	    parenthesis_counter--;
        } else {
	    if(!(strcmp(type_flag2, "func_or_var"))) { 
		if(!(strcmp(x, "="))) {
		    strcpy(str_dummy_dest, content_buffer);
		    strcpy(str_dummy_src, " := ");
		    strcat(str_dummy_dest, str_dummy_src);
		    content = str_dummy_dest;
		    fprintf(fp, "%s", content);
		    buffer_used = "true";
		} else if(strstr(x, ";")) {
		    content = strtok(x, ";");
		    fprintf(fp, "%s", content);
		    if(!(strcmp(buffer_used, "false"))) {
		        content = content_buffer;
		        fprintf(fp, "%s", content);
		    }
		    content = ";";
		    fprintf(fp, "%s\n", content);
		    type_flag2 = "first_time";
		    if(!strcmp(if_flag, "end_if")) {
	                content = endings->prev->buffer;
	                /* Write content to file */
                        fprintf(fp, "%s\n", content);
	                endings = endings->prev;
	                free(endings->next);
		        if_flag = "none";
		    }
		} else {
	            content = x; 
	            fprintf(fp, "%s", content);
		}
	    } else {
		content = x; 
	        fprintf(fp, "%s", content);
	    }
	}
	if(strstr(x, ";")) {
	    content = ""; 
	    fprintf(fp, "%s\n", content);
	}
    }

    fclose(fp);
}
