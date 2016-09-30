/*achieve who order
*currently login username :ut_name
*port name :ut_line
*time :ut_time 
*/

#include<stdio.h>
#include<stdlib.h>
#include<utmp.h>
#include<fcntl.h>
#include<unistd.h>

void show_info(struct utmp *utm)
{
  printf("%-8.8s\t",utm->ut_name);
  printf("%-8.8s\t",utm->ut_line);
  show_time(utm->ut_time);
  printf("%s\n",utm->ut_host);
}

void show_time(long timevar)
{
   char *now;
   now=ctime(&timevar); 
   printf("%20.20s",now+4);
}
int main()
{
   int fd_utmp;
   struct utmp current_record;
   int reclen=sizeof(current_record);
   
   if((fd_utmp=open(UTMP_FILE,O_RDONLY))==-1)
   {
      perror(UTMP_FILE);
      exit(1);
   }
   while((read(fd_utmp,&current_record,reclen))==reclen)
   {
      show_info(&current_record);
   }
   close(fd_utmp);
    return 0;
}
