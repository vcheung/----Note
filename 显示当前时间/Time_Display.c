/*
 * 函数名：Time_Display
 * 描述  ：显示当前时间值
 * 输入  ：-TimeVar RTC计数值，单位为 s
 * 输出  ：无
 */	
void Time_Display(uint32_t TimeVar)
{
	uint32_t THH = 0, TMM = 0, TSS = 0;
	
	/* Compute  hours
	 * 将极速器中的值换成时分秒分别赋给THH ，TMM，TSS */
	THH = TimeVar / 3600;
	/* Compute minutes */
	TMM = (TimeVar % 3600) / 60;
	/* Compute seconds */
	TSS = (TimeVar % 3600) % 60;
	
	/* 将时间传到上位机上显示 */
	printf(" Time: %0.2d:%0.2d:%0.2d\r", THH, TMM, TSS);
}