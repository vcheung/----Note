/*
 * 函数名：Time_Regulate
 * 描述  ：返回用户在超级终端中输入的时间值，并将值储存在
 *         RTC 计数寄存器中。
 * 输入  ：无
 * 输出  ：用户在超级终端中输入的时间值，单位为 s
 * 调用  ：被Time_Adjust调用，调用USART_Scanf
 */
uint32_t Time_Regulate(void)
{
	uint32_t Tmp_HH = 0xFF, Tmp_MM = 0xFF, Tmp_SS = 0xFF;
	
	printf("\r\n==============Time Settings=====================================");
	printf("\r\n  Please Set Hours");
	
	while (Tmp_HH == 0xFF)
	{
		/* 将串口接受的数据给Tmp_HH ，23便是传递给USART_Scanf（value）中的形参value的 */
		Tmp_HH = USART_Scanf(23);
	}
	printf(":  %d", Tmp_HH);
	printf("\r\n  Please Set Minutes");
	while (Tmp_MM == 0xFF)
	{
		Tmp_MM = USART_Scanf(59);
	}
	printf(":  %d", Tmp_MM);
	printf("\r\n  Please Set Seconds");
	while (Tmp_SS == 0xFF)
	{
		Tmp_SS = USART_Scanf(59);
	}
	printf(":  %d", Tmp_SS);
	
	/* Return the value to store in RTC counter register
	 * 将时分秒转换成秒放入RTC计数器中 */
	return((Tmp_HH*3600 + Tmp_MM*60 + Tmp_SS));
}