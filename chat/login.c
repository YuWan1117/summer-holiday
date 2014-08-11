
void login ()
{
	int 	conn_fd;
	int 	count = 0;

	//实现客户端与服务器的连接
	conn_fd = link_server ();

	//用户身份验证，三次机会
	while ( count < 3 ) {
		if ( user_login ( conn_fd ) == 0 ) {
		      //登陆成功
		      printf ( "\n\n\t\tCongratrulation!\n" );

		      //暂停：使用户看到提示信息
		      getchar ();
		      break;
		}
		else {
		      //登录失败
		      count++;
		}
	}

	if ( count == 3 ) {
		printf ( "your have made it three times, so the system command you to exit.\n" );
		
		//暂停：使用户看到提示信息
		getchar ();
		exit (1);
	} 
	
	//否则就是进行聊天communication
}
