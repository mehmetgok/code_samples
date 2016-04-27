#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>


static volatile int keepRunning = 1;

void intrHandler(int dummy) {
    keepRunning = 0;
}

#define TABLE "CREATE TABLE IF NOT EXISTS TTC (id INTEGER PRIMARY KEY AUTOINCREMENT, millis BIGINT)"

int main(int argc, char* argv[]){
	
   struct timeval start, end;

   long mtime, seconds, useconds;    
   
   int id = 0;
   int i;
   sqlite3 *db;
   sqlite3_stmt * stmt;
   
   char * sErrMsg = 0;
	
	
   char *zErrMsg = 0;
   int rc;
   
   signal(SIGINT, intrHandler);
   
   rc = sqlite3_open("test.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
	  
	  sqlite3_exec(db, TABLE, NULL, NULL, &sErrMsg);  
	  
	  // Free table
	   sqlite3_exec(db, "delete from TTC", NULL, NULL, &sErrMsg);  
	  
	  
   }
   
   sqlite3_exec(db, "BEGIN TRANSACTION", NULL, NULL, &sErrMsg);
   
   char buffer[] = "INSERT INTO TTC(millis) VALUES (?1)";
	
	sqlite3_prepare_v2(db, buffer, strlen(buffer), &stmt, NULL);
   
    while (keepRunning) 
	{ 
	
	    gettimeofday(&start, NULL);
		usleep(1000);
		gettimeofday(&end, NULL);
		
		useconds =  (end.tv_sec*1000000 + end.tv_usec) - (start.tv_sec*1000000 + start.tv_usec);
		
		
		// sqlite3_bind_int(stmt, 1, ++id);
		 sqlite3_bind_int(stmt, 1, useconds);
 
		if (sqlite3_step(stmt) != SQLITE_DONE)
		{
			printf("Commit Failed!\n");
		}
 
		sqlite3_reset(stmt);
		
		
   }
   
   
   sqlite3_exec(db, "END TRANSACTION", NULL, NULL, &sErrMsg);  
   
   sqlite3_finalize(stmt);
   
   printf("Write OK\r\n");
   
   
   sqlite3_close(db);
}