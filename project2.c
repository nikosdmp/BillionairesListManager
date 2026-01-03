#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int year;
  int month;
  int day;
}date;

typedef struct
{
  int hour;
  int minutes;
}birthtime;

typedef struct bilList
{
  char *name;
  char *country;
  char *activity;
  char *origins;
  char *gender;
  date birthdate;
  birthtime birthhour;
  float value;

  struct bilList *next;
  struct bilList *prev;
}billionaire;

//Xrhsh global kefalhs kai ouras gia eykolia ths xrhshs twn leitourgiwn twn synarthsewn kai ths main xwris na xrhsimopoihsoume diplo *
struct bilList *head=NULL;
struct bilList *tail=NULL;

char *strcasestr(const char *haystack, const char *needle);
//Entoles programmatos
void help(); //Tutorial entolwn programmatos
void newbil(char *input);
void sum();
void findN(char *input);
void findC(char *input);
void findS(char *input);
void print_over(char *input);
void print_under(char *input);
void print_equal(char *input);
void deleteN();
void deleteO();
void load(char *input);
void save(char *input);


int main(void)
{
  char *input, *copy, *test, *check;
  char end_condition[]="exit";
  int size;
  help();
  input=(char*)malloc(sizeof(char)); //Entolh xrhsth
  copy=(char*)malloc(sizeof(char));  //Apothhkeush entolhs xrhsth
  test=(char*)malloc(sizeof(char));  //Apotelesma strtok() entolhs xrhsth
  check=(char*)malloc(sizeof(char)); //Apomonosh entolhs xrhsth apo parametrous px check=="load" otan input=="load 18 billionaires.txt"
   while (strcmp(end_condition,copy)!=0 && strcmp(end_condition,copy)!=10)
   {
       printf("Ti thelete na kanete twra?:\n");
	   printf("$> ");
	   scanf("\n%m[^\n]", &input); //Apothhkeush entolhs xrhsth sto input
	   size=strlen(input);
	   copy=(char*)malloc(size * sizeof(char));
	   test=(char*)malloc(size * sizeof(char));
	   strcpy(copy, input);
	   strcpy(test, copy);
	   check=strtok(copy, " ");   //H strtok() kovei to string se kommatia analoga to pou thelei o xrhsths, de symperilambanetai to keno
	   while (test!=NULL)         //Adeiazoume to buffer ths strtok()
	   {
         test=strtok(NULL, " ");
	   }
	   if (strcmp(check, "help")==0)
	   {
		 help();
	   }
       else if (strcmp(check, "exit")==0)
	   {
		 printf("Proetoimasia ejodou...\n");
	   }
       else if (strcmp(check, "newbil")==0)
	   {
		 newbil(input);
	   } 
       else if (strcmp(check, "sum")==0)
	   {
		 sum();
	   } 
       else if (strcmp(check, "findN")==0)
	   {
		 findN(input);
	   } 
       else if (strcmp(check, "findC")==0)
	   {
		 findC(input);
	   } 
       else if (strcmp(check, "findS")==0)
	   {
		 findS(input);
	   } 
       else if (strcmp(check, "print+")==0)
	   {
		 print_over(input);
	   } 
       else if (strcmp(check, "print-")==0)
	   {
		 print_under(input);
	   } 
       else if (strcmp(check, "print=")==0)
	   {
		 print_equal(input);
	   } 
       else if (strcmp(check, "deleteN")==0)
	   {
		 deleteN();
	   } 
       else if (strcmp(check, "deleteO")==0)
	   {
		 deleteO();
	   } 
       else if (strcmp(check, "load")==0)
	   {
		 load(input);
	   } 
       else if (strcmp(check, "save")==0)
	   {
		 save(input);
	   } 
       else
	   {
		 printf("Mh yparkth entolh, dokimaste jana: \n");
	   }
    }
	printf("Ejodos.\n");
	return 0;
}

void help()
{
    printf("Dwste thn epomenh entolh, parakatw oi diathesimes entoles: \n");
	printf("To * mporei na xrhsimopoihthei meta apo opoiadhpote 'Find... *' gia na ektypwsoume apla th lista.\n");
  	printf("'findC': Ektypwnei olous tous disekatommyriouxous twn opoiwn h polh/xwra drasthriothtas perilambanei tous xarakthres pou plhktrologhthikan me th seira.\n");
    printf("'findS': Ektypwnei olous tous disekatommyriouxous twn opoiwn h phgh eisodhmatos perilambanei tous xarakthres pou plhktrologhthikan me th seira.\n");
    printf("'findN': Ektypwnei olous tous disekatommyriouxous twn opoiwn to onoma perilambanei tous xarakthres pou plhktrologhthikan me ayth th seira.\n");
	printf("'print-': Ektypwnei olous tous disekatommyriouxous twn opoiwn h ajia/genethlia/wra gennhshs einai katw apo thn timh pou dinetai.\n");
	printf("'print=': Ektypwnei olous tous disekatommyriouxous twn opoiwn h ajia/genethlia/wra gennhshs einai ish me thn ajia pou dinetai.\n");
    printf("'print+': Ektypwnei olous tous disekatommyriouxous twn opoiwn h ajia/genethlia/wra gennhshs yperbainei thn ajia pou dinetai.\n");
    printf("'sum': Ginetai prosthesh tou synolikou athroismatos olwn twn apothikeymenwn periousiakwn stoixeiwn twn disekatommyriouxwn.\n");
    printf("'save [onoma.txt]' Apothikeuei thn trexousa lista me tous disekatommyriouxous dhmiourgwntas ena arxeio txt.\n");
    printf("'load [x] [onoma.txt]' Fortwnei mia list[x(arithmos)] disekatmmyriouxwn apo ena epilegmeno arxeio txt.\n");
    printf("'deleteO': Diagrafei to palaiotero stoixeio pou prostethike sth lista\n");
    printf("'deleteN': Diagrafei to neotero stoixeio pou prostethike sth lista.\n");
    printf("'newbil': Prosthesh enos disekatommyriouxou sth lista.\n");
	printf("'help': Kanei na emfanistei ayto to menu.\n");
	printf("'exit': Amesh ejodos apo to programma.\n");
}
void newbil(char *input)
{
    struct bilList *new_node=(struct bilList*)malloc(sizeof(struct bilList));
	char *copy, *test, **parts, *city, *country,*date, *time, *day, *month, *year, *hour, *minute, *output;
	int size,i,days,months,years,hours,minutes,flagDT=0,flagCC=0,space_count=0;
	size=strlen(input);
	parts=(char**)malloc(7 * sizeof(char*));
	copy=(char*)malloc(size * sizeof(char));
	test=(char*)malloc(size * sizeof(char));
	strcpy(copy, input);
	test=strtok(copy, " ");
	for (i=0; i<7; i++)
	{
	   test=strtok(NULL, ";");
	   if (test!=NULL)
	   {
	     parts[i]=(char*)malloc((strlen(test)+1) * sizeof(char)); //Dynamikh kataxwrhsh mnhmhs sto parts[i] analoga to megethos tou test ana kommati tou input
	     strcpy(parts[i],test);
	   } 
       else
	   {
		 printf("Lanthasmenh morfh gia to newbil, dokimaste jana: \n");
		 return;
	   }
	}
	//Diaxwrismos drasthriothtwn ean yparxoun polles apo aytes me megala kena metajy tous pou prepei na diortwthoun
	copy=(char*)malloc((strlen(parts[2])+1) * sizeof(char));
	test=(char*)malloc((strlen(parts[2])+1) * sizeof(char));
	output=(char*)malloc((strlen(parts[2]+10)) * sizeof(char));
	strcpy(copy,parts[2]);
	test=strtok(copy, "\t");
	strcpy(output,test);
	int first_pass=1;
	while (test!=NULL && strcmp(test,parts[2])!=0)
	{
	   if (first_pass==1)
	   {
		 strcat(output, ","); //Enwnei dyo alfarithmhtika, px string1 string2 ,strcat(string1, string2) == "string1string2"
		 first_pass=0;
	   }
	   test = strtok(NULL, " ");
	   if (test!=NULL)
	   {
		   if (first_pass!=0)
		   {
			 strcat(output, ",");
		   }
			first_pass=2;
			strcat(output,test);
	   }
	}
	strcpy(parts[2],output);
	//Diaxwrismos timwn ean einai aparaithto logw kartelwn sto arxiko arxeio disekatommyriouxwn pou tha odhghsoun se times opws to 80  7 pou tha eprepe na einai 80,7 alla diabazetai 807
	copy=(char*)malloc((strlen(parts[6])+1) * sizeof(char));
	test=(char*)malloc((strlen(parts[6])+1) * sizeof(char));
	output=(char*)malloc((strlen(parts[6]+1)) * sizeof(char));
	strcpy(copy,parts[6]);
	test=strtok(copy, "\t");
	strcpy(output,test);
	first_pass=1;
	while (test!=NULL && strcmp(test,parts[6])!=0)
	{
	   if (first_pass==1)
	   {
		 strcat(output, ".");
		 first_pass=0;
	   }
	   test=strtok(NULL, " ");
	   if (test!=NULL)
	   {
		 strcat(output,test);
	   }
	}
	strcpy(parts[6],output);
	//Diaxwrismos polhs/xwras drasthriothtas gia na tis dokimasoume kai na tis enhmerwsoume ean einai aparaithto
    copy=(char*)malloc((strlen(parts[1])+1) * sizeof(char));
	test=(char*)malloc((strlen(parts[1])+1) * sizeof(char));
	strcpy(copy, parts[1]);
	test=strtok(copy, "/");
	city=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(city, test);
	test=strtok(NULL, "/");
	country=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(country, test);
	//Xwrismos wras kai hmerominias
	copy=(char*)malloc((strlen(parts[5])+1) * sizeof(char));
	test=(char*)malloc((strlen(parts[5])+1) * sizeof(char));
	strcpy(copy, parts[5]);
	test=strtok(copy, " ");
	date=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(date, test);
	test=strtok(NULL, " ");
	time=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(time, test);
	//Xwrismos hmeromhnias se hmera/mhna/etos
	copy=(char*)malloc((strlen(date)+1) * sizeof(char));
	test=(char*)malloc((strlen(date)+1) * sizeof(char));
	strcpy(copy, date);
	test=strtok(copy, "/");
	day=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(day, test);
	test=strtok(NULL, "/");
	month=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(month, test);
	test=strtok(NULL, "/");
	year=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(year, test);
	//Diaxwrismos xronou se wres kai lepta
	copy=(char*)malloc((strlen(time)+1) * sizeof(char));
	test=(char*)malloc((strlen(time)+1) * sizeof(char));
	strcpy(copy, time);
	test=strtok(copy, ":");
	hour=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(hour, test);
	test=strtok(NULL, ":");
	minute=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(minute, test);
	//Metatroph xwristwn timwn symboloseirwn se akeraious arithmous
	days=atoi(day);
	months=atoi(month);
	years=atoi(year);
	hours=atoi(hour);
	minutes=atoi(minute);
	//Elegxoi dedomenwn pou edwse o xrhsths ana kathgoria
	if (days<0 || days>31 || (days>29 && months==2))
	{
	  printf("Adynatos arithmos hmerwn...\n");
	  flagDT=1;
	}
	if (months<0 || months>12)
	{
	  printf("Adynatos arithmos mhnwn...\n");
	  flagDT=1;
	}
	if (years<0)
	{
	  printf("Adynatos arithmos etwn...\n");
	  flagDT=1;
	}
	if (hours<0 || hours>24)
	{
	  printf("Adynatos arithmos wrwn se morfh 24wrou...\n");
	  flagDT=1;
	}
	if (minutes<0 || minutes>59)
	{
	  printf("Adynatos arithmos leptwn...\n");
	  flagDT=1;
	}
	if (strcmp(city, "?")==0)
	{
	  strcpy(city, "Agnwstos");
	  flagCC=1;
	}
	if (strcmp(country, "?")==0)
	{
	  strcpy(country, "Agnwstos");
	  flagCC=1;
	}
	if (flagCC==1) //flagCC gia na doume oti mporei kai prepei na ksanaenwthei to city me to country kai na mpoun sto parts[1] ws "city/country"
	{
	  strcat(city, "/");
	  strcat(city,country);
	  strcpy(parts[1],city);
	}
	if (flagDT==0) //flagDT shmainei oti kapoio value sta day/month/year hour/minute eixe dwthei lathos ara den tha ginei eisagwgh sthn lista
	{
	    new_node->next=NULL;
		new_node->prev=NULL;
		new_node->name=(char*)malloc((strlen(parts[0])+1) * sizeof(char));
		new_node->country=(char*)malloc((strlen(parts[1])+1) * sizeof(char));
		new_node->activity=(char*)malloc((strlen(parts[2])+1) * sizeof(char));
		new_node->origins=(char*)malloc((strlen(parts[3])+1) * sizeof(char));
		new_node->gender=(char*)malloc((strlen(parts[4])+1) * sizeof(char));
		strcpy((new_node->name),parts[0]);
		strcpy((new_node->country),parts[1]);
		strcpy((new_node->activity),parts[2]);
		strcpy((new_node->origins),parts[3]);
		strcpy((new_node->gender),parts[4]);
		new_node->birthdate.day=days;
		new_node->birthdate.month=months;
		new_node->birthdate.year=years;
		new_node->birthhour.hour=hours;
		new_node->birthhour.minutes=minutes;
		new_node->value=atof(parts[6]);
		//Dhmiourgia head an den yparxei, alliws dhmiourgia neou node sto telos ths listas
		if (head==NULL)
		{
		  head=new_node;
		  tail=new_node;
		} 
        else
		{
		  new_node->prev=tail;
		  tail->next=new_node;
		  tail=new_node;
		}
		//Stamata h apostolh apo to struct
	}
	//Telos ths synarthshs 187
}

//Anatrexoume thn lista kai prosthetoume to tail->value (*tail).value (temp_tail->value) sto sum, gia na paroume to synolo twn dis $ pou briskontai sthn lista
void sum()
{
	struct bilList *temp_head=head;
	struct bilList *temp_tail=tail;
	float sum=0;
	if (temp_head!=NULL)
	{
	  temp_tail=temp_head;
	  while (temp_tail!=NULL)
	   {
		 sum=sum+(temp_tail->value);
		 temp_tail=temp_tail->next;
	   }
	   printf("sum: %.2f\n",sum);
	} 
    else
	{
	  printf("Den yparxei epalhtheymenos disekatommyriouxos sth lista, epomenws de mporei na ektypwthei poso.\n");
	}
}

void findN(char *input)
{
	struct bilList *temp_head=head;
	struct bilList *temp_tail=tail;
	char *copy, *test, *str;
	int size, i=0;
	size=strlen(input);
	copy=(char*)malloc((size+1) * sizeof(char));
	test=(char*)malloc((size+1) * sizeof(char));
	strcpy(copy,input);
	strcpy(test,copy);
	test=strtok(copy, " ");
	test=strtok(NULL, " ");
	//Elegxos gia segmentation meta thn ektelesh mias entolhs xwris kamia symboloseira na thn akolouthei
	if (test!=NULL)
	{
	  str=(char*)malloc((strlen(test)+1) * sizeof(char));
	} 
	else
	{
	  printf("Lanthasmenh morfh, dokimaste jana: \n");
	  return;
	}
	strcpy(str, test);
	if (temp_head!=NULL)
	{
		if (str!=NULL)
		{
			temp_tail=temp_head;
			printf("           %-*s %-*s %-*s %-*s %-*s %-*s %-*s\n",50,"Onoma",
								      30,"Polh/Xwra",
								      30,"Drasthriothta",
								      20,"Topos Gennhshs",
								      10,"Fylo",
								      20,"Genethlia",
								      6,"Ajia");
			for (i=0; i<190; i++)
			{
			  printf("-");
			}
			i=0;
			printf("\n");
			while (temp_tail!=NULL)
			{//strcasestr() elegxei gia to an to string pou dinei o xrhsths emperiexetai sto temp_tail->name gia kathe name sthn lista ana perasma ths while
				if (strcasestr((temp_tail->name), str)!=NULL || strcmp(str, "*")==0)
				{
					i++;
					printf("%-*d| ",6,i);
					printf(" %-*s ",50,temp_tail->name);
					printf(" %-*s ",30,temp_tail->country);
					printf(" %-*s ",30,temp_tail->activity);
					printf(" %-*s ",20,temp_tail->origins);
					printf(" %-*s ",8,temp_tail->gender);
					printf("%*d/",2,temp_tail->birthdate.day);
					printf("%*d/",2,temp_tail->birthdate.month);
					printf("%-*d ",4,temp_tail->birthdate.year);
					if (temp_tail->birthhour.hour<10)
					{
					  printf("0%d:",temp_tail->birthhour.hour);
					} 
                    else
					{
					  printf("%d:",temp_tail->birthhour.hour);
					}
					if (temp_tail->birthhour.minutes<10)
					{
					  printf("0%-*d   ",4,temp_tail->birthhour.minutes);
					} 
                    else
					{
					  printf("%-*d    ",4,temp_tail->birthhour.minutes);
					}
					printf("%-*.2f\n",6,temp_tail->value);
				}
				temp_tail=temp_tail->next;
			}
		} 
        else
		{
		  printf("Den dothike onoma gia anazhthsh.\n");
		}
	} 
    else
	{
	  printf("Den yparxei epalhtheymenos disekatommyriouxos sth lista, epomenws de mporei na diejaxthei anazhthsh.\n");
	}
	//Telos synarthshs
}

void findC(char *input)
{
	struct bilList *temp_head=head;
	struct bilList *temp_tail=tail;
	char *copy, *test, *str;
	int size, i=0;
	size=strlen(input);
	copy=(char*)malloc((size+1) * sizeof(char));
	test=(char*)malloc((size+1) * sizeof(char));
	strcpy(copy,input);
	strcpy(test,copy);
	test=strtok(copy, " ");
	test=strtok(NULL, " ");
	//Elegxos gia segmentation meta thn ektelesh mias entolhs xwris kamia symboloseira na thn akolouthei
	if (test!=NULL)
	{
	  str=(char*)malloc((strlen(test)+1) * sizeof(char));
	} 
	else
	{
	  printf("Lanthasmenh morfh, dokimaste jana: \n");
	  return;
	}
	strcpy(str, test);
	if (temp_head!=NULL)
	{
		if (str!=NULL)
		{
			temp_tail=temp_head;
			printf("           %-*s %-*s %-*s %-*s %-*s %-*s %-*s\n",50,"Onoma",
								      30,"Polh/Xwra",
								      30,"Drasthriothta",
								      20,"Topos Gennhshs",
								      10,"Fylo",
								      20,"Genethlia",
								      6,"Ajia");
			for (i=0; i<190; i++)
			{
			  printf("-");
			}
			i=0;
			printf("\n");
			while (temp_tail!=NULL)
			{
				if (strcasestr((temp_tail->country), str)!=NULL || strcmp(str, "*")==0 || strcasestr((temp_tail->origins), str)!=NULL)
                //Typwnei kai osous exoun gennhthei se mia xwra alla de drasthriopiountai ekei pleon (me to deytero strcasestr)
				{ 
					i++;
					printf("%-*d| ",6,i);
					printf(" %-*s ",50,temp_tail->name);
					printf(" %-*s ",30,temp_tail->country);
					printf(" %-*s ",30,temp_tail->activity);
					printf(" %-*s ",20,temp_tail->origins);
					printf(" %-*s ",8,temp_tail->gender);
					printf("%*d/",2,temp_tail->birthdate.day);
					printf("%*d/",2,temp_tail->birthdate.month);
					printf("%-*d ",4,temp_tail->birthdate.year);
					if (temp_tail->birthhour.hour<10)
					{
					  printf("0%d:",temp_tail->birthhour.hour);
					} 
                    else
					{
					  printf("%d:",temp_tail->birthhour.hour);
					}
					if (temp_tail->birthhour.minutes<10)
					{
					  printf("0%-*d   ",4,temp_tail->birthhour.minutes);
					}
                    else
					{
					  printf("%-*d    ",4,temp_tail->birthhour.minutes);
					}
					printf("%-*.2f\n",6,temp_tail->value);
				}
				temp_tail=temp_tail->next;
			}
		} 
        else
		{
		  printf("Den dothike onoma gia anazhthsh.\n");
		}
	} 
    else
	{
	  printf("Den yparxei epalhtheymenos disekatommyriouxos sth lista, epomenws de mporei na diejaxthei anazhthsh.\n");
	}
	//Telos synarthshs
}

void findS(char *input)
{
	struct bilList *temp_head=head;
	struct bilList *temp_tail=tail;
	char *copy, *test, *str;
	int size, i=0;
	size=strlen(input);
	copy=(char*)malloc((size+1) * sizeof(char));
	test=(char*)malloc((size+1) * sizeof(char));
	strcpy(copy,input);
	strcpy(test,copy);
	test=strtok(copy, " ");
	test=strtok(NULL, " ");
	//Elegxos gia segmentation meta thn ektelesh mias entolhs xwris kamia symboloseira na thn akolouthei
	if (test!=NULL)
	{
	  str=(char*)malloc((strlen(test)+1) * sizeof(char));
	} 
	else
	{
	  printf("Lanthasmenh morfh, dokimaste jana: \n");
	  return;
	}
	strcpy(str, test);
	if (temp_head!=NULL)
	{
		if (str!=NULL)
		{
			temp_tail=temp_head;
			printf("           %-*s %-*s %-*s %-*s %-*s %-*s %-*s\n",50,"Onoma",
								      30,"Polh/Xwra",
								      30,"Drasthriothta",
								      20,"Topos Gennhshs",
								      10,"Fylo",
								      20,"Genethlia",
								      6,"Ajia");
			for (i=0; i<190; i++)
			{
			  printf("-");
			}
			i=0;
			printf("\n");
			while (temp_tail!=NULL)
			{
				if (strcasestr((temp_tail->activity), str)!=NULL || strcmp(str, "*")==0)
				{ 
					i++;
					printf("%-*d| ",6,i);
					printf(" %-*s ",50,temp_tail->name);
					printf(" %-*s ",30,temp_tail->country);
					printf(" %-*s ",30,temp_tail->activity);
					printf(" %-*s ",20,temp_tail->origins);
					printf(" %-*s ",8,temp_tail->gender);
					printf("%*d/",2,temp_tail->birthdate.day);
					printf("%*d/",2,temp_tail->birthdate.month);
					printf("%-*d ",4,temp_tail->birthdate.year);
					if (temp_tail->birthhour.hour<10)
					{
					  printf("0%d:",temp_tail->birthhour.hour);
					} 
                    else
					{
					  printf("%d:",temp_tail->birthhour.hour);
					}
					if (temp_tail->birthhour.minutes<10)
					{
					  printf("0%-*d   ",4,temp_tail->birthhour.minutes);
					} 
                    else
					{
					  printf("%-*d    ",4,temp_tail->birthhour.minutes);
					}
					printf("%-*.2f\n",6,temp_tail->value);
				}
				temp_tail=temp_tail->next;
			}
		} 
        else
		{
		  printf("Den dothike onoma gia anazhthsh.\n");
		}
	} 
    else
	{
	  printf("Den yparxei epalhtheymenos disekatommyriouxos sth lista, epomenws de mporei na diejaxthei anazhthsh.\n");
	}
	//Telos synarthshs
}

void print_over(char *input)
{
	struct bilList *temp_head=head;
	struct bilList *temp_tail=tail;
	char *copy, *test, *str;
	int size, i=0,flag=0,d=1,m=1,y=1900,h=0,mnt=0;
	float money=0;
	size=strlen(input);
	copy=(char*)malloc((size+1) * sizeof(char));
	test=(char*)malloc((size+1) * sizeof(char));
	strcpy(copy,input);
	strcpy(test,copy);
	test=strtok(copy, " ");
	test=strtok(NULL, " ");
	if (test!=NULL)
	{
	  str=(char*)malloc((strlen(test)+1) * sizeof(char));
	} 
    else
	{
	  printf("Lanthasmenh morfh, dokimaste jana: \n");
	  return;
	}
	strcpy(str, test);
	//Diabazoume to str kai koitame an yparxei to katallhlo format ana anagkh (hmeromhnia/wra)
	int check_for_time=sscanf(str, "%d:%d",&h,&mnt);
	int check_for_date=sscanf(str, "%d/%d/%d",&d,&m,&y);
	//An o xrhsths exei dwsei hmeromhnia (dd/mm/yyyy) to check_for_date tha einai 3
	//An o xrhsths exei dwsei wra (hh:mm) to check_for_time tha einai 2
	if (check_for_date==3)
	{
		//Elegxoi gia to an h hmeromhnia pou exei dwsei o xrhsths yparxei
		if (d>0 && m>0 && y>0 && d<31 && m<12)
		{
			flag=1;
		} 
        else
		{
		  printf("Dothike lanthasmenh morfh: %d/%d/%d\n",d,m,y);
		  printf("Swsth anamenomenh morfh: dd/mm/yyyy\n");
		  printf("Lanthasmenh morfh hmeromhnias, dokimaste jana: \n");
		}
	} 
    else if (check_for_time==2)
	{
		//Elegxoi gia to an h wra pou exei dwsei o xrhsths yparxei
		if ((h>=0 && h<24) && (mnt>=0 && mnt<60))
		{
		  flag=2;
		} 
        else
		{
		  printf("Adynath wra, dinetai se morfh 24wrwn: \n");
		}
	} 
    else if (atof(str)>0)
	{
		//Dinoume thn float timh tou str sto money wste meta na sygkrithei me to value tou kathe disekatommyriouxou
		money=atof(str);
		flag=3;
	} 
    else
	{
	  printf("Lanthasmenh morfh, dokimaste jana: \n");
	}
	if (temp_head!=NULL)
	{
		if (str!=NULL)
		{
			temp_tail=temp_head;
			printf("           %-*s %-*s %-*s %-*s %-*s %-*s %-*s\n",50,"Onoma",
								      30,"Polh/Xwra",
								      30,"Drasthriothta",
								      20,"Topos Gennhshs",
								      10,"Fylo",
								      20,"Genethlia",
								      6,"Ajia");
			for (i=0; i<190; i++)
			{
			  printf("-");
			}
			i=0;
			printf("\n");
			while (temp_tail!=NULL)
			{
				switch (flag) 
				{
				  case 1:
				   if (((temp_tail->birthdate.year)>y) || ((temp_tail->birthdate.year)>=y && (temp_tail->birthdate.month)>m) || ((temp_tail->birthdate.year)>=y && (temp_tail->birthdate.month)>=m && (temp_tail->birthdate.day)>d))
				   { 
						i++;
						printf("%-*d| ",6,i);
						printf(" %-*s ",50,temp_tail->name);
						printf(" %-*s ",30,temp_tail->country);
						printf(" %-*s ",30,temp_tail->activity);
						printf(" %-*s ",20,temp_tail->origins);
						printf(" %-*s ",8,temp_tail->gender);
						printf("%*d/",2,temp_tail->birthdate.day);
						printf("%*d/",2,temp_tail->birthdate.month);
						printf("%-*d ",4,temp_tail->birthdate.year);
						if (temp_tail->birthhour.hour<10)
					    {
						  printf("0%d:",temp_tail->birthhour.hour);
					    } 
                        else
					    {
						  printf("%d:",temp_tail->birthhour.hour);
					    }
						if (temp_tail->birthhour.minutes<10)
					    {
						  printf("0%-*d   ",4,temp_tail->birthhour.minutes);
					    } 
                        else
					    {
						  printf("%-*d    ",4,temp_tail->birthhour.minutes);
					    }
					    printf("%-*.2f\n",6,temp_tail->value);
				    }
					
				break;
				  case 2:
				   if (((temp_tail->birthhour.hour)>h) || ((temp_tail->birthhour.hour)>=h && (temp_tail->birthhour.minutes)>mnt))
				   { 
						i++;
						printf("%-*d| ",6,i);
						printf(" %-*s ",50,temp_tail->name);
						printf(" %-*s ",30,temp_tail->country);
						printf(" %-*s ",30,temp_tail->activity);
						printf(" %-*s ",20,temp_tail->origins);
						printf(" %-*s ",8,temp_tail->gender);
						printf("%*d/",2,temp_tail->birthdate.day);
						printf("%*d/",2,temp_tail->birthdate.month);
						printf("%-*d ",4,temp_tail->birthdate.year);
						if (temp_tail->birthhour.hour<10)
					    {
						  printf("0%d:",temp_tail->birthhour.hour);
						} 
                        else
						{
						  printf("%d:",temp_tail->birthhour.hour);
						}
						if (temp_tail->birthhour.minutes<10)
						{
						  printf("0%-*d   ",4,temp_tail->birthhour.minutes);
						} 
                        else
						{
						  printf("%-*d    ",4,temp_tail->birthhour.minutes);
						}
						printf("%-*.2f\n",6,temp_tail->value);
				    }
				break;
				  case 3:
					if ((temp_tail->value)>money)
					{	 
						i++;
						printf("%-*d| ",6,i);
						printf(" %-*s ",50,temp_tail->name);
						printf(" %-*s ",30,temp_tail->country);
						printf(" %-*s ",30,temp_tail->activity);
						printf(" %-*s ",20,temp_tail->origins);
						printf(" %-*s ",8,temp_tail->gender);
						printf("%*d/",2,temp_tail->birthdate.day);
						printf("%*d/",2,temp_tail->birthdate.month);
						printf("%-*d ",4,temp_tail->birthdate.year);
						if (temp_tail->birthhour.hour<10)
						{
							printf("0%d:",temp_tail->birthhour.hour);
						} 
                        else
						{
						  printf("%d:",temp_tail->birthhour.hour);
						}
						if (temp_tail->birthhour.minutes<10)
						{
						  printf("0%-*d   ",4,temp_tail->birthhour.minutes);
						} 
                        else
						{
						  printf("%-*d    ",4,temp_tail->birthhour.minutes);
						}
						printf("%-*.2f\n",6,temp_tail->value);
					}	
				break;
				 default:
					//Apotyxia...
				break;
				}
				temp_tail=temp_tail->next;
			}
		} 
        else
		{
		  printf("Den dothike onoma gia anazhthsh.\n");
		}
	} 
    else
	{
	  printf("Den yparxei epalhtheymenos disekatommyriouxos sth lista, epomenws de mporei na diejaxthei anazhthsh.\n");
	}
	//Telos synarthshs
}

void print_under(char *input)
{
	struct bilList *temp_head=head;
	struct bilList *temp_tail=tail;
	char *copy, *test, *str;
	int size, i=0,flag=0,d=1,m=1,y=1900,h=0,mnt=0;
	float money=0;
	size=strlen(input);
	copy=(char*)malloc((size+1) * sizeof(char));
	test=(char*)malloc((size+1) * sizeof(char));
	strcpy(copy,input);
	strcpy(test,copy);
	test=strtok(copy, " ");
	test=strtok(NULL, " ");
	if (test!=NULL)
	{
	  str=(char*)malloc((strlen(test)+1) * sizeof(char));
	} 
    else
	{
	  printf("Lanthasmenh morfh, dokimaste jana: \n");
	  return;
	}
	strcpy(str, test);

	int check_for_time=sscanf(str, "%d:%d",&h,&mnt);
	int check_for_date=sscanf(str, "%d/%d/%d",&d,&m,&y);

	if (check_for_date==3)
	{
		if (d>0 && m>0 && y>0 && d<31 && m<12)
		{
		  flag=1;
		}
         else
		{
		  printf("Dothike lanthasmenh morfh: %d/%d/%d\n",d,m,y);
		  printf("Swsth anamenomenh morfh: dd/mm/yyyy\n");
		  printf("Lanthasmenh morfh hmeromhnias, dokimaste jana: \n");
		}
	} 
    else if (check_for_time==2)
	{
		if ((h>=0 && h<24) && (mnt>=0 && mnt<60))
		{
		  flag=2;
		} 
        else
		{
		  printf("Adynath wra, dinetai se morfh 24wrwn, dokimaste jana: \n");
		}
	} 
    else if (atof(str)!=0)
	{
	  money=atof(str);
	  flag=3;
	} 
    else
	{
	  printf("Lanthasmenh morfh, dokimaste jana: \n");
	}
	if (temp_head!=NULL)
	{
		if (str!=NULL)
		{
			temp_tail=temp_head;
			printf("           %-*s %-*s %-*s %-*s %-*s %-*s %-*s\n",50,"Onoma",
								      30,"Polh/Xwra",
								      30,"Drasthriothta",
								      20,"Topos Gennhshs",
								      10,"Fylo",
								      20,"Genethlia",
								      6,"Ajia");
			for (i=0; i<190; i++)
			{
			  printf("-");
			}
			i=0;
			printf("\n");
			while (temp_tail!=NULL)
			{
				switch (flag) 
				{
				  case 1:
					if (((temp_tail->birthdate.year)<y) || ((temp_tail->birthdate.year)<=y && (temp_tail->birthdate.month)<m) || ((temp_tail->birthdate.year)<=y && (temp_tail->birthdate.month)<=m && (temp_tail->birthdate.day)<d))
					{ 
						i++;
						printf("%-*d| ",6,i);
						printf(" %-*s ",50,temp_tail->name);
						printf(" %-*s ",30,temp_tail->country);
						printf(" %-*s ",30,temp_tail->activity);
						printf(" %-*s ",20,temp_tail->origins);
						printf(" %-*s ",8,temp_tail->gender);
						printf("%*d/",2,temp_tail->birthdate.day);
						printf("%*d/",2,temp_tail->birthdate.month);
						printf("%-*d ",4,temp_tail->birthdate.year);
						if (temp_tail->birthhour.hour<10)
						{
						  printf("0%d:",temp_tail->birthhour.hour);
						} 
                        else
						{
						  printf("%d:",temp_tail->birthhour.hour);
						}
						if (temp_tail->birthhour.minutes<10)
						{
						  printf("0%-*d   ",4,temp_tail->birthhour.minutes);
						} 
                        else
						{
						  printf("%-*d    ",4,temp_tail->birthhour.minutes);
						}
						printf("%-*.2f\n",6,temp_tail->value);
					}
					
				break;
				  case 2:
					if (((temp_tail->birthhour.hour)<h) || ((temp_tail->birthhour.hour)<=h && (temp_tail->birthhour.minutes)<mnt))
					{ 
						i++;
						printf("%-*d| ",6,i);
						printf(" %-*s ",50,temp_tail->name);
						printf(" %-*s ",30,temp_tail->country);
						printf(" %-*s ",30,temp_tail->activity);
						printf(" %-*s ",20,temp_tail->origins);
						printf(" %-*s ",8,temp_tail->gender);
						printf("%*d/",2,temp_tail->birthdate.day);
						printf("%*d/",2,temp_tail->birthdate.month);
						printf("%-*d ",4,temp_tail->birthdate.year);
						if (temp_tail->birthhour.hour<10)
						{
							printf("0%d:",temp_tail->birthhour.hour);
						} 
                        else
						{
						  printf("%d:",temp_tail->birthhour.hour);
						}
						if (temp_tail->birthhour.minutes<10)
						{
						  printf("0%-*d   ",4,temp_tail->birthhour.minutes);
						} 
                        else
						{
						  printf("%-*d    ",4,temp_tail->birthhour.minutes);
						}
						printf("%-*.2f\n",6,temp_tail->value);
					}
				break;
				  case 3:
					if ((temp_tail->value)<money)
					{	 
						i++;
						printf("%-*d| ",6,i);
						printf(" %-*s ",50,temp_tail->name);
						printf(" %-*s ",30,temp_tail->country);
						printf(" %-*s ",30,temp_tail->activity);
						printf(" %-*s ",20,temp_tail->origins);
						printf(" %-*s ",8,temp_tail->gender);
						printf("%*d/",2,temp_tail->birthdate.day);
						printf("%*d/",2,temp_tail->birthdate.month);
						printf("%-*d ",4,temp_tail->birthdate.year);
						if (temp_tail->birthhour.hour<10)
						{
						  printf("0%d:",temp_tail->birthhour.hour);
						} 
                        else
						{
						  printf("%d:",temp_tail->birthhour.hour);
						}
						if (temp_tail->birthhour.minutes<10)
						{
						  printf("0%-*d   ",4,temp_tail->birthhour.minutes);
						} 
                        else
						{
						  printf("%-*d    ",4,temp_tail->birthhour.minutes);
						}
						printf("%-*.2f\n",6,temp_tail->value);
					}	
				break;
				 default:
					//Apotyxia...
				break;
				}
				temp_tail=temp_tail->next;
			}
		} 
        else
		{
		  printf("Den dothike onoma gia anazhthsh.\n");
		}
	} 
    else
	{
	  printf("Den yparxei epalhtheymenos disekatommyriouxos sth lista, epomenws de mporei na diejaxthei anazhthsh.\n");
	}
	//Telos synarthshs
}

void print_equal(char *input)
{
	struct bilList *temp_head=head;
	struct bilList *temp_tail=tail;
	char *copy, *test, *str;
	int size, i=0,flag=0,d=1,m=1,y=1900,h=0,mnt=0;
	float money=0;
	size=strlen(input);
	copy=(char*)malloc((size+1) * sizeof(char));
	test=(char*)malloc((size+1) * sizeof(char));
	strcpy(copy,input);
	strcpy(test,copy);
	test=strtok(copy, " ");
	test=strtok(NULL, " ");
	if (test!=NULL)
	{
	  str=(char*)malloc((strlen(test)+1) * sizeof(char));
	} 
    else
	{
	  printf("Lanthasmenh morfh, dokimaste jana: \n");
	  return;
	}
	strcpy(str, test);

	int check_for_time=sscanf(str, "%d:%d",&h,&mnt);
	int check_for_date=sscanf(str, "%d/%d/%d",&d,&m,&y);

	if (check_for_date==3)
	{
		if (d>0 && m>0 && y>0 && d<31 && m<12)
		{
	      flag=1;
		} 
        else
		{
		  printf("Dothike lanthasmenh morfh: %d/%d/%d\n",d,m,y);
		  printf("Swsth anamenomenh morfh: dd/mm/yyyy\n");
		  printf("Lanthasmenh morfh hmeromhnias, dokimaste jana: \n");
		}
	} 
    else if (check_for_time==2)
	{
		if ((h>=0 && h<24) && (mnt>=0 && mnt<60))
		{
		  flag=2;
		} 
        else
		{
		  printf("Adynath wra, dinetai se morfh 24wrwn, dokimaste jana: \n");
		}
	} 
    else if (atof(str)!=0)
	{
	  money=atof(str);
	  flag=3;
	} 
    else
	{
	  printf("Lanthasmenh morfh, dokimaste jana: \n");
	}
	if (temp_head!=NULL)
	{
		if (str!=NULL)
		{
			temp_tail=temp_head;
			printf("           %-*s %-*s %-*s %-*s %-*s %-*s %-*s\n",50,"Onoma",
								      30,"Polh/Xwra",
								      30,"Drasthriothta",
								      20,"Topos Gennhshs",
								      10,"Fylo",
								      20,"Genethlia",
								      6,"Ajia");
			for (i=0; i<190; i++)
			{
			  printf("-");
			}
			i=0;
			printf("\n");
			while (temp_tail!=NULL)
			{
				switch (flag) 
				{
				  case 1:
					if (((temp_tail->birthdate.year)==y && (temp_tail->birthdate.month)==m) )
					{ 
						i++;
						printf("%-*d| ",6,i);
						printf(" %-*s ",50,temp_tail->name);
						printf(" %-*s ",30,temp_tail->country);
						printf(" %-*s ",30,temp_tail->activity);
						printf(" %-*s ",20,temp_tail->origins);
						printf(" %-*s ",8,temp_tail->gender);
						printf("%*d/",2,temp_tail->birthdate.day);
						printf("%*d/",2,temp_tail->birthdate.month);
						printf("%-*d ",4,temp_tail->birthdate.year);
						if (temp_tail->birthhour.hour<10)
						{
						  printf("0%d:",temp_tail->birthhour.hour);
						} 
                        else
						{
						  printf("%d:",temp_tail->birthhour.hour);
						}
						if (temp_tail->birthhour.minutes<10)
						{
						  printf("0%-*d   ",4,temp_tail->birthhour.minutes);
						} 
                        else
						{
						  printf("%-*d    ",4,temp_tail->birthhour.minutes);
						}
						printf("%-*.2f\n",6,temp_tail->value);
					}
					
				break;
				  case 2:
					if (((temp_tail->birthhour.hour)==h && (temp_tail->birthhour.minutes)==mnt))
					{ 
						i++;
						printf("%-*d| ",6,i);
						printf(" %-*s ",50,temp_tail->name);
						printf(" %-*s ",30,temp_tail->country);
						printf(" %-*s ",30,temp_tail->activity);
						printf(" %-*s ",20,temp_tail->origins);
						printf(" %-*s ",8,temp_tail->gender);
						printf("%*d/",2,temp_tail->birthdate.day);
						printf("%*d/",2,temp_tail->birthdate.month);
						printf("%-*d ",4,temp_tail->birthdate.year);
						if (temp_tail->birthhour.hour<10)
						{
						  printf("0%d:",temp_tail->birthhour.hour);
						} 
						else
						{
						  printf("%d:",temp_tail->birthhour.hour);
						}
						if (temp_tail->birthhour.minutes<10)
						{
						  printf("0%-*d   ",4,temp_tail->birthhour.minutes);
						} 
						else
						{
						  printf("%-*d    ",4,temp_tail->birthhour.minutes);
						}
						printf("%-*.2f\n",6,temp_tail->value);
					}
				break;
				  case 3:
					if ((temp_tail->value)==money)
					{	 
						i++;
						printf("%-*d| ",6,i);
						printf(" %-*s ",50,temp_tail->name);
						printf(" %-*s ",30,temp_tail->country);
						printf(" %-*s ",30,temp_tail->activity);
						printf(" %-*s ",20,temp_tail->origins);
						printf(" %-*s ",8,temp_tail->gender);
						printf("%*d/",2,temp_tail->birthdate.day);
						printf("%*d/",2,temp_tail->birthdate.month);
						printf("%-*d ",4,temp_tail->birthdate.year);
						if (temp_tail->birthhour.hour<10)
						{
						  printf("0%d:",temp_tail->birthhour.hour);
						} 
                        else
						{
						  printf("%d:",temp_tail->birthhour.hour);
						}
						if (temp_tail->birthhour.minutes<10)
						{
						  printf("0%-*d   ",4,temp_tail->birthhour.minutes);
						} 
                        else
						{
						  printf("%-*d    ",4,temp_tail->birthhour.minutes);
						}
						printf("%-*.2f\n",6,temp_tail->value);
					}	
				break;
				  default:
					//Apotyxia...
				break;
				}
				temp_tail=temp_tail->next;
			}
		}
        else
		{
		  printf("Den dothike onoma gia anazhthsh.\n");
		}
	} 
    else
	{
	  printf("Den yparxei epalhtheymenos disekatommyriouxos sth lista, epomenws de mporei na diejaxthei anazhthsh.\n");
	}
	//Telos synarthshs
}

void deleteN()
{
	if (head!=NULL)
	{
	  tail=tail->prev;
	  tail->next=NULL;
	}
}

void deleteO()
{
	if (head!=NULL)
	{
	  head=head->next;
	}
}

void load(char *input)
{
	char *copy, *test, **parts, *city, *country,*date, *time, *day, *month, *year, *hour, *minute, *output, *number, *filename, str[200];
	int size,i,days,months,years,hours,minutes,flagDT=0,flagCC=0,space_count=0,file_number=0,pass_counter=0;
	FILE *myfile;
	
	//Pairnoume to input tou xrhstsh kai kai to kanoume tokenise gia thn apokthsh twn "load" "number" "filename"
	size=strlen(input);
	copy=(char*)malloc(size * sizeof(char));
	test=(char*)malloc(size * sizeof(char));
	strcpy(copy, input);
	test=strtok(copy, " ");
	test=strtok(NULL, " ");
	//Elegxos gia segmentation meta thn ektelesh mias entolhs xwris kamia symboloseira na thn akolouthei
	if (test!=NULL)
	{
	  number=(char*)malloc((strlen(test)+1) * sizeof(char));
	} 
	else
	{
	  printf("Lanthasmenh morfh, dokimaste jana: \n");
	  return;
	}
	if (test!=NULL)
	{
		strcpy(number,test);
		file_number=atoi(number);
        if (file_number<0)
        {
          printf("H fortwsh den einai efikth, dioti eisagontai mono thetikoi arithmoi, dokimaste jana: \n");
          return;
        }
	}
	test=strtok(NULL, " ");
	//Elegxos gia segmentation meta thn ektelesh mias entolhs xwris kamia symboloseira na thn akolouthei
	if (test!=NULL)
	{
	  filename=(char*)malloc((strlen(test)+1) * sizeof(char));
	} 
	else
	{
	  printf("Den dothike onoma arxeiou, dokimaste jana: \n");
	  return;
	}
	if (test!=NULL)
	{
	  strcpy(filename, test);
	}
	if (filename==NULL || file_number==0)
	{
	  printf("Lanthasmenh eisodos, dokimaste jana: \n");
	  return;
	}
	myfile=fopen(filename,"r");
	if (myfile==NULL)
	{
	  printf("Ayto to arxeio den yparxei h de mporei na entopistei, dokimaste jana:\n");
	  return;
	}
	while (pass_counter<file_number)
	{
	if (fgets(str, sizeof(str), myfile)!=NULL)
	{
	struct bilList *new_node = (struct bilList*)malloc(sizeof(struct bilList));
	if (new_node==NULL)
	{
	  printf("H desmeush mnhmhs apetyxe\n");
	  exit(1);
	}
	size=strlen(str);
	parts=(char**)malloc(7 * sizeof(char*));
	copy=(char*)malloc(size * sizeof(char));
	test=(char*)malloc(size * sizeof(char));
	strcpy(copy, str);
	test=strtok(copy, ";");
	for (i=0; i<7; i++)
	{
		if (test!=NULL)
		{
		  parts[i]=(char*)malloc((strlen(test)+1) * sizeof(char));
		  strcpy(parts[i],test);
		  test=strtok(NULL, ";");
		} 
        else
		{
		  printf("Brethike lathos morfh dedomenwn sto arxeio, h fortwsh stamata edw\n");
		  return;
		}
	}
	//Diaxwrismos drasthriothtwn ean yparxoun polles apo aytes me megala kena metajy tous pou prepei na diortwthoun
	copy=(char*)malloc((strlen(parts[2])+1) * sizeof(char));
	test=(char*)malloc((strlen(parts[2])+1) * sizeof(char));
	output=(char*)malloc((strlen(parts[2])+10) * sizeof(char));
	strcpy(copy,parts[2]);
	test=strtok(copy, "\t");
	strcpy(output,test);
	int first_pass=1;
	while (test!=NULL && strcmp(test,parts[2])!=0)
	{
		if (first_pass==1)
		{
		  strcat(output, ",");
		  first_pass=0;
		}
		test=strtok(NULL, "\t");
		if (test!=NULL)
		{
			if (first_pass!=0)
			{
			  strcat(output,",");
			}
			first_pass=2;
			strcat(output,test);
		} 
	}
	strcpy(parts[2],output);
	//Diaxwrismos timwn ean einai aparaithto logw kartelwn sto arxiko arxeio disekatommyriouxwn pou tha odhghsoun se times opws to 80  7 pou tha eprepe na einai 80,7 alla diabazetai 807
	copy=(char*)malloc((strlen(parts[6])+1) * sizeof(char));
	test=(char*)malloc((strlen(parts[6])+1) * sizeof(char));
	output=(char*)malloc((strlen(parts[6]+1)) * sizeof(char));
	strcpy(copy,parts[6]);
	test=strtok(copy, "\t");
	strcpy(output,test);
	first_pass=1;
	while (test!=NULL && strcmp(test,parts[6])!=0)
	{
		if (first_pass==1)
		{
		  strcat(output, ".");
		  first_pass=0;
		}
		test=strtok(NULL, " ");
		if (test!=NULL)
		{
		  strcat(output,test);
		}
	}
	strcpy(parts[6],output);
	//Diaxwrismos polhs/xwras drasthriothtas gia na tis dokimasoume kai na tis enhmerwsoume ean einai aparaithto
    copy=(char*)malloc((strlen(parts[1])+1) * sizeof(char));
	test=(char*)malloc((strlen(parts[1])+1) * sizeof(char));
	strcpy(copy, parts[1]);
	test=strtok(copy, "/");
	city=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(city, test);
	test=strtok(NULL, "/");
	country=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(country, test);
	//Diaxwrismos wras kai hmeromhnias
	copy=(char*)malloc((strlen(parts[5])+1) * sizeof(char));
	test=(char*)malloc((strlen(parts[5])+1) * sizeof(char));
	strcpy(copy, parts[5]);
	test=strtok(copy, " ");
	date=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(date, test);
	test=strtok(NULL, " ");
	time=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(time, test);
	//Diaxwrismos hmerominias se hmera/mhna/etos
	copy=(char*)malloc((strlen(date)+1) * sizeof(char));
	test=(char*)malloc((strlen(date)+1) * sizeof(char));
	strcpy(copy, date);
	test=strtok(copy, "/");
	day=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(day, test);
	test=strtok(NULL, "/");
	month=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(month, test);
	test=strtok(NULL, "/");
	year=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(year, test);
	//Diaxwrismos xronou se wra kai lepta
	copy=(char*)malloc((strlen(time)+1) * sizeof(char));
	test=(char*)malloc((strlen(time)+1) * sizeof(char));
	strcpy(copy, time);
	test=strtok(copy, ":");
	hour=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(hour, test);
	test=strtok(NULL, ":");
	minute=(char*)malloc((strlen(test)+1) * sizeof(char));
	strcpy(minute, test);
	//Metatroph xwristwn timwn symboloseirwn se akeraious arithmous
	days=atoi(day);
	months=atoi(month);
	years=atoi(year);
	hours=atoi(hour);
	minutes=atoi(minute);
	if (days<0 || days>31 || (days>29 && months==2))
	{
	  printf("Adynatos arithmos hmerwn...\n");
	  flagDT=1;
	}
	if (months<0 || months>12)
	{
	  printf("Adynatos arithmos mhnwn...\n");
	  flagDT=1;
	}
	if (years<0)
	{
	  printf("Adynatos arithmos etwn...\n");
	  flagDT=1;
	}
	if (hours<0 || hours>24)
	{
	  printf("Adynatos arithmos se morfh 24wrou...\n");
	  flagDT=1;
	}
	if (minutes<0 || minutes>59)
	{
	  printf("Adynatos arithmos leptwn...\n");
	  flagDT=1;
	}
	if (strcmp(city, "?")==0)
	{
	  strcpy(city, "Agnwstos");
	  flagCC=1;
	}
	if (strcmp(country, "?")==0)
	{
	  strcpy(country, "Agnwstos");
	  flagCC=1;
	}
	if (flagCC==1)
	{
	  strcat(city, "/");
	  strcat(city,country);
	  strcpy(parts[1],city);
	}
	if (flagDT==0)
	{
		new_node->next=NULL;
		new_node->prev=NULL;
		new_node->name=(char*)malloc((strlen(parts[0])+1) * sizeof(char));
		new_node->country=(char*)malloc((strlen(parts[1])+1) * sizeof(char));
		new_node->activity=(char*)malloc((strlen(parts[2])+1) * sizeof(char));
		new_node->origins=(char*)malloc((strlen(parts[3])+1) * sizeof(char));
		new_node->gender=(char*)malloc((strlen(parts[4])+1) * sizeof(char));
		strcpy((new_node->name),parts[0]);
		strcpy((new_node->country),parts[1]);
		strcpy((new_node->activity),parts[2]);
		strcpy((new_node->origins),parts[3]);
		strcpy((new_node->gender),parts[4]);
		new_node->birthdate.day=days;
		new_node->birthdate.month=months;
		new_node->birthdate.year=years;
		new_node->birthhour.hour=hours;
		new_node->birthhour.minutes=minutes;
		new_node->value=atof(parts[6]);
		if (head==NULL)
		{
		  head=new_node;
		  tail=new_node;
		} 
        else
		{
		  new_node->prev=tail;
		  tail->next=new_node;
		  tail=new_node;
		}
		
		free(copy);
		free(day);
		free(month);
		free(year);
		free(hour);
		free(minute);
		free(parts);
		//Stamata h apostolh apo to struct
	}
	}
	pass_counter++;
	}
	fclose(myfile);
	//Telos synarthshs
}

void save(char *input)
{
	//Apothhkeush listas se arxeio xrhsimopoiwntas thn fopen(), fprintf() kai thn lista
	struct bilList *temp_head=head;
	struct bilList *temp_tail=tail;
	char *copy, *test, *filename;
	int size;
	FILE *myfile;
	size=strlen(input);
	copy=(char*)malloc(size * sizeof(char));
	test=(char*)malloc(size * sizeof(char));
	strcpy(copy, input);
	test=strtok(copy, " ");
	test=strtok(NULL, " ");
	//Elegxos gia segmentation meta thn ektelesh mias entolhs xwris kamia symboloseira na thn akolouthei
    if (test!=NULL)
	{
	  filename=(char*)malloc((strlen(test)+1) * sizeof(char));
	} 
	else
	{
	  printf("Den dothike onoma arxeiou, dokimaste jana: \n");
	  return;
	}
	strcpy(filename,test);
	if (filename!=NULL)
	{
	   myfile=fopen(filename,"w+");
	   if (myfile==NULL)
	    {
		  printf("Aytou tou typou to arxeio den yparxei...\n");
		  return;
	    }
	}
	while (temp_head!=NULL)
	{
		fprintf(myfile, "%s",temp_head->name);
		fprintf(myfile, ";");
		fprintf(myfile, "%s",temp_head->country);
		fprintf(myfile, ";");
		fprintf(myfile, "%s",temp_head->activity);
		fprintf(myfile, ";");
		fprintf(myfile, "%s",temp_head->origins);
		fprintf(myfile, ";");
		fprintf(myfile, "%s",temp_head->gender);
		fprintf(myfile, ";");
		fprintf(myfile, "%d",temp_head->birthdate.day);
		fprintf(myfile, "/");
		fprintf(myfile, "%d",temp_head->birthdate.month);
		fprintf(myfile, "/");
		fprintf(myfile, "%d",temp_head->birthdate.year);
		fprintf(myfile, " ");
		if ((temp_head->birthhour.hour)<10) //Se periptwsh opou h wra h ta lepta pou exoun dwthei einai <10 tote grafetai mprosta ena 0 wste na einai px 03:02
		{
		  fprintf(myfile, "0%d",temp_head->birthhour.hour);
		} 
        else
		{
		  fprintf(myfile, "%d",temp_head->birthhour.hour);
		}
		if ((temp_head->birthhour.minutes)<10)
		{
		  fprintf(myfile, ":0%d",temp_head->birthhour.minutes);
		} 
        else
		{
		  fprintf(myfile, ":0%d",temp_head->birthhour.minutes);
		}
		fprintf(myfile, ";");
		fprintf(myfile, "%.1f\n",temp_head->value);
		temp_head=temp_head->next;
	}
}