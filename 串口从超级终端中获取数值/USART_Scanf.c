/*
 * ��������USART_Scanf
 * ����  �����ڴӳ����ն��л�ȡ��ֵ
 * ����  ��- value �û��ڳ����ն����������ֵ
 * ���  ����
 * ����  ���ڲ����ã���Time_Regulate(void)����
 */ 
uint8_t USART_Scanf(uint32_t value)
{
	uint32_t index = 0;
	uint32_t tmp[2] = {0, 0};
	
	while (index < 2)
	{
		/* Loop until RXNE = 1
		 * �ȴ����ݽ�����ɣ�����������������ʱ��״̬�Ĵ�����USART_FLAG_RXNE�ͻ�Ϊ1 */
		while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET)
		{}
		/* �����ݸ�����tmp, �Ӵ����ն��������ȥ������ASCII��ֵ */
		tmp[index++] = (USART_ReceiveData(USART1));
		/* �Ӵ����ն��������ȥ������ASCII��ֵ
		 * �жϽ��ܵ��������Ƿ���0��9֮�� */
		if ((tmp[index - 1] < 0x30) || (tmp[index - 1] > 0x39))
		{
			printf("\n\rPlease enter valid number between 0 and 9");
			index--;
		}
	}
	/* Calculate the Corresponding value
	 * �����ܵ������������һ����λ�� */
	index = (tmp[1] - 0x30) + ((tmp[0] - 0x30) * 10);
	/* Checks
	 * �ж���ɺ��ֵ�Ƿ����ޣ�������ɵ�Сʱ���ܳ���23�����벻�ܳ���59��
	 * value ��Ϊ23����59 */
	if (index > value)
	{
		printf("\n\rPlease enter valid number between 0 and %d", value);
		return 0xFF;
	}
	return index;
}