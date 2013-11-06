/*
 * 函数名：USART_Scanf
 * 描述  ：串口从超级终端中获取数值
 * 输入  ：- value 用户在超级终端中输入的数值
 * 输出  ：无
 * 调用  ：内部调用，被Time_Regulate(void)调用
 */ 
uint8_t USART_Scanf(uint32_t value)
{
	uint32_t index = 0;
	uint32_t tmp[2] = {0, 0};
	
	while (index < 2)
	{
		/* Loop until RXNE = 1
		 * 等待数据接受完成，当接收引脚有数据时，状态寄存器的USART_FLAG_RXNE就会为1 */
		while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET)
		{}
		/* 将数据给数组tmp, 从串口终端里面输进去的数是ASCII码值 */
		tmp[index++] = (USART_ReceiveData(USART1));
		/* 从串口终端里面输进去的数是ASCII码值
		 * 判断接受到的数据是否在0到9之间 */
		if ((tmp[index - 1] < 0x30) || (tmp[index - 1] > 0x39))
		{
			printf("\n\rPlease enter valid number between 0 and 9");
			index--;
		}
	}
	/* Calculate the Corresponding value
	 * 将接受的两个数据组成一个两位数 */
	index = (tmp[1] - 0x30) + ((tmp[0] - 0x30) * 10);
	/* Checks
	 * 判断组成后的值是否有无，比如组成的小时不能超过23，分秒不能超过59，
	 * value 即为23，或59 */
	if (index > value)
	{
		printf("\n\rPlease enter valid number between 0 and %d", value);
		return 0xFF;
	}
	return index;
}