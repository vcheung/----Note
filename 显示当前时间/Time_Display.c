/*
 * ��������Time_Display
 * ����  ����ʾ��ǰʱ��ֵ
 * ����  ��-TimeVar RTC����ֵ����λΪ s
 * ���  ����
 */	
void Time_Display(uint32_t TimeVar)
{
	uint32_t THH = 0, TMM = 0, TSS = 0;
	
	/* Compute  hours
	 * ���������е�ֵ����ʱ����ֱ𸳸�THH ��TMM��TSS */
	THH = TimeVar / 3600;
	/* Compute minutes */
	TMM = (TimeVar % 3600) / 60;
	/* Compute seconds */
	TSS = (TimeVar % 3600) % 60;
	
	/* ��ʱ�䴫����λ������ʾ */
	printf(" Time: %0.2d:%0.2d:%0.2d\r", THH, TMM, TSS);
}