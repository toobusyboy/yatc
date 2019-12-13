/* diamond.c源文件 */
/*********************************************************** 
 * 功能:	打印菱形
 **********************************************************/
void diamond()
{
	int i, j;     /*定义循环变量*/
	int k;      	/*定义变量保存用户的输入*/
	
	printf("请输入菱形大小:");
	scanf("%d",&k);
	
	/*循环开始打印出空心菱形的上半部分，
	  外循环控制行数，内循环控制每行的输出*/	
	for (i = 0; i < k; i=i+1)
	{
		/*控制菱形左边的空格输出*/
		for (j = 0; j < k-1-i; j=j+1)       
		{
			printf(" ");   
		}
		
		/*如果是菱形的边界用"*"输出，否则用空格填充*/
		for (j = 0; j < 2*i+1; j=j+1)       
		{
			if ( 0 == j)
			{
				printf("*");
			}
			else if (2 * i == j)
				printf("*");
			else 
			{
				printf(" "); 
			}
			
		}
		printf("\n");  /*每行结束的时候换行*/
	}
	
	/*循环开始打印出空心菱形的下半部分，
	  外循环控制行数，内循环控制每行的输出*/ 
	for (i = k-2; i >= 0; i=i-1)
	{
		/*控制菱形左边的空格输出*/
		for (j = 0; j < k-1-i; j=j+1)          
		{
			printf(" ");   
		}
		
		/*如果是菱形的边界用"*"输出，否则用空格填充*/
		for (j = 0; j < 2*i+1; j=j+1)          
		{
			if ( 0 == j)
			{
				printf("*");
			}
			else if (2 * i == j)
				printf("*");
			else 
			{
				printf(" "); 
			}
		}
		printf("\n");  /*每行结束的时候换行*/
	}
}


/*********************************************************** 
 * 功能:	main函数
 **********************************************************/
int  main()
{
	diamond();	
	return 0;
}

/*********************************************************** 
 * 功能:	入口函数
 **********************************************************/
void  _entry()
{
	int ret;
	ret = main();
	exit(ret);
}