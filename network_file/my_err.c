//display the error 
void my_err ( char *string, int line )
{
	fprintf ( stderr, "line: %d.\n", line );
	perror ( string );

	//record the error to the file of error
	record_err ( string );

	//make it exit
	exit (1);
}

//record the error to the file of error
void record_err ( char *string )
{
	//the file's discribtion
	int 	fd;

	//open the file 
	if ( ( fd = open ( "./error", O_RDWR|O_CREAT|O_APPEND ) ) == -1 ) {
		perror ( "open" );
		exit (1);
	}

	//write the function name of the error
	record_wr ( fd, string );

	//write the "error"
	if ( write ( fd, " error ", 7 ) != 7 ) {
		perror ( "write" );
		exit (1);
	}

	//write the time to the file
	record_time ( fd );

	close ( fd );
}

//write the error function's name
void record_wr ( int fd, char *string )
{
	if ( write ( fd, string, strlen (string) ) != strlen (string) ) {
		perror ( "write" );
		exit (1);
	}
}

//write the time to the file
void record_time ( int fd )
{
	time_t 	now;

	time ( &now );

	if ( write ( fd, ctime ( &now ), strlen ( ctime (&now) ) ) != strlen ( ctime (&now) ) ) {
		perror ( "write" );
		exit (1);
	}
}

