#include "dac.h"

#define sinesize 300
#define offset 120

#define DAC_DHR12RD_Address      0x40007420

s16 const _Sine12bit[sinesize] = {
0x0800,0x07D5,0x07AA,0x077F,0x0755,0x072A,0x06FF,0x06D5,0x06AB,0x0680,
0x0656,0x062D,0x0603,0x05DA,0x05B0,0x0587,0x055F,0x0536,0x050E,0x04E7,
0x04BF,0x0498,0x0472,0x044C,0x0426,0x0401,0x03DC,0x03B7,0x0393,0x0370,
0x034D,0x032A,0x0309,0x02E7,0x02C6,0x02A6,0x0287,0x0268,0x0249,0x022C,
0x020F,0x01F2,0x01D7,0x01BC,0x01A2,0x0188,0x016F,0x0157,0x0140,0x0129,
0x0113,0x00FE,0x00EA,0x00D6,0x00C4,0x00B2,0x00A1,0x0091,0x0081,0x0073,
0x0065,0x0058,0x004C,0x0041,0x0037,0x002E,0x0025,0x001E,0x0017,0x0011,
0x000C,0x0008,0x0005,0x0003,0x0001,0x0001,0x0001,0x0003,0x0005,0x0008,
0x000C,0x0011,0x0017,0x001E,0x0025,0x002E,0x0037,0x0041,0x004C,0x0058,
0x0065,0x0073,0x0081,0x0091,0x00A1,0x00B2,0x00C4,0x00D6,0x00EA,0x00FE,
0x0113,0x0129,0x0140,0x0157,0x016F,0x0188,0x01A2,0x01BC,0x01D7,0x01F2,
0x020F,0x022C,0x0249,0x0268,0x0287,0x02A6,0x02C6,0x02E7,0x0309,0x032A,
0x034D,0x0370,0x0393,0x03B7,0x03DC,0x0401,0x0426,0x044C,0x0472,0x0498,
0x04BF,0x04E7,0x050E,0x0536,0x055F,0x0587,0x05B0,0x05DA,0x0603,0x062D,
0x0656,0x0680,0x06AB,0x06D5,0x06FF,0x072A,0x0755,0x077F,0x07AA,0x07D5,
0x0800,0x082B,0x0856,0x0881,0x08AB,0x08D6,0x0901,0x092B,0x0955,0x0980,
0x09AA,0x09D3,0x09FD,0x0A26,0x0A50,0x0A79,0x0AA1,0x0ACA,0x0AF2,0x0B19,
0x0B41,0x0B68,0x0B8E,0x0BB4,0x0BDA,0x0BFF,0x0C24,0x0C49,0x0C6D,0x0C90,
0x0CB3,0x0CD6,0x0CF7,0x0D19,0x0D3A,0x0D5A,0x0D79,0x0D98,0x0DB7,0x0DD4,
0x0DF1,0x0E0E,0x0E29,0x0E44,0x0E5E,0x0E78,0x0E91,0x0EA9,0x0EC0,0x0ED7,
0x0EED,0x0F02,0x0F16,0x0F2A,0x0F3C,0x0F4E,0x0F5F,0x0F6F,0x0F7F,0x0F8D,
0x0F9B,0x0FA8,0x0FB4,0x0FBF,0x0FC9,0x0FD2,0x0FDB,0x0FE2,0x0FE9,0x0FEF,
0x0FF4,0x0FF8,0x0FFB,0x0FFD,0x0FFF,0x0FFF,0x0FFF,0x0FFD,0x0FFB,0x0FF8,
0x0FF4,0x0FEF,0x0FE9,0x0FE2,0x0FDB,0x0FD2,0x0FC9,0x0FBF,0x0FB4,0x0FA8,
0x0F9B,0x0F8D,0x0F7F,0x0F6F,0x0F5F,0x0F4E,0x0F3C,0x0F2A,0x0F16,0x0F02,
0x0EED,0x0ED7,0x0EC0,0x0EA9,0x0E91,0x0E78,0x0E5E,0x0E44,0x0E29,0x0E0E,
0x0DF1,0x0DD4,0x0DB7,0x0D98,0x0D79,0x0D5A,0x0D3A,0x0D19,0x0CF7,0x0CD6,
0x0CB3,0x0C90,0x0C6D,0x0C49,0x0C24,0x0C00,0x0BDA,0x0BB4,0x0B8E,0x0B68,
0x0B41,0x0B19,0x0AF2,0x0ACA,0x0AA1,0x0A79,0x0A50,0x0A26,0x09FD,0x09D3,
0x09AA,0x0980,0x0955,0x092B,0x0901,0x08D6,0x08AB,0x0881,0x0856,0x082B};

s16 const Sine12bit[sinesize] = {
0x0800,0x082B,0x0856,0x0881,0x08AB,0x08D6,0x0901,0x092B,0x0955,0x0980,
0x09AA,0x09D3,0x09FD,0x0A26,0x0A50,0x0A79,0x0AA1,0x0ACA,0x0AF2,0x0B19,
0x0B41,0x0B68,0x0B8E,0x0BB4,0x0BDA,0x0C00,0x0C24,0x0C49,0x0C6D,0x0C90,
0x0CB3,0x0CD6,0x0CF7,0x0D19,0x0D3A,0x0D5A,0x0D79,0x0D98,0x0DB7,0x0DD4,
0x0DF1,0x0E0E,0x0E29,0x0E44,0x0E5E,0x0E78,0x0E91,0x0EA9,0x0EC0,0x0ED7,
0x0EED,0x0F02,0x0F16,0x0F2A,0x0F3C,0x0F4E,0x0F5F,0x0F6F,0x0F7F,0x0F8D,
0x0F9B,0x0FA8,0x0FB4,0x0FBF,0x0FC9,0x0FD2,0x0FDB,0x0FE2,0x0FE9,0x0FEF,
0x0FF4,0x0FF8,0x0FFB,0x0FFD,0x0FFF,0x0FFF,0x0FFF,0x0FFD,0x0FFB,0x0FF8,
0x0FF4,0x0FEF,0x0FE9,0x0FE2,0x0FDB,0x0FD2,0x0FC9,0x0FBF,0x0FB4,0x0FA8,
0x0F9B,0x0F8D,0x0F7F,0x0F6F,0x0F5F,0x0F4E,0x0F3C,0x0F2A,0x0F16,0x0F02,
0x0EED,0x0ED7,0x0EC0,0x0EA9,0x0E91,0x0E78,0x0E5E,0x0E44,0x0E29,0x0E0E,
0x0DF1,0x0DD4,0x0DB7,0x0D98,0x0D79,0x0D5A,0x0D3A,0x0D19,0x0CF7,0x0CD6,
0x0CB3,0x0C90,0x0C6D,0x0C49,0x0C24,0x0C00,0x0BDA,0x0BB4,0x0B8E,0x0B68,
0x0B41,0x0B19,0x0AF2,0x0ACA,0x0AA1,0x0A79,0x0A50,0x0A26,0x09FD,0x09D3,
0x09AA,0x0980,0x0955,0x092B,0x0901,0x08D6,0x08AB,0x0881,0x0856,0x082B,
0x0800,0x07D5,0x07AA,0x077F,0x0755,0x072A,0x06FF,0x06D5,0x06AB,0x0680,
0x0656,0x062D,0x0603,0x05DA,0x05B0,0x0587,0x055F,0x0536,0x050E,0x04E7,
0x04BF,0x0498,0x0472,0x044C,0x0426,0x0401,0x03DC,0x03B7,0x0393,0x0370,
0x034D,0x032A,0x0309,0x02E7,0x02C6,0x02A6,0x0287,0x0268,0x0249,0x022C,
0x020F,0x01F2,0x01D7,0x01BC,0x01A2,0x0188,0x016F,0x0157,0x0140,0x0129,
0x0113,0x00FE,0x00EA,0x00D6,0x00C4,0x00B2,0x00A1,0x0091,0x0081,0x0073,
0x0065,0x0058,0x004C,0x0041,0x0037,0x002E,0x0025,0x001E,0x0017,0x0011,
0x000C,0x0008,0x0005,0x0003,0x0001,0x0001,0x0001,0x0003,0x0005,0x0008,
0x000C,0x0011,0x0017,0x001E,0x0025,0x002E,0x0037,0x0041,0x004C,0x0058,
0x0065,0x0073,0x0081,0x0091,0x00A1,0x00B2,0x00C4,0x00D6,0x00EA,0x00FE,
0x0113,0x0129,0x0140,0x0157,0x016F,0x0188,0x01A2,0x01BC,0x01D7,0x01F2,
0x020F,0x022C,0x0249,0x0268,0x0287,0x02A6,0x02C6,0x02E7,0x0309,0x032A,
0x034D,0x0370,0x0393,0x03B7,0x03DC,0x0401,0x0426,0x044C,0x0472,0x0498,
0x04BF,0x04E7,0x050E,0x0536,0x055F,0x0587,0x05B0,0x05DA,0x0603,0x062D,
0x0656,0x0680,0x06AB,0x06D5,0x06FF,0x072A,0x0755,0x077F,0x07AA,0x07D5};


s32 DualSine12bit[sinesize];
s32 _DualSine12bit[sinesize];
s32 ADDR[2];
//DAC通道1输出初始化
void Dac1_Init(void)
{
    GPIO_InitTypeDef    GPIO_InitStructure;
    DAC_InitTypeDef     DAC_InitStructure;
    DMA_InitTypeDef     DMA_InitStructure;
    NVIC_InitTypeDef    NVIC_InitStructure;

    u16 Idx;
    for (Idx = 0; Idx < sinesize; Idx++)
    {
        DualSine12bit[Idx] = ((Sine12bit[Idx]/2 + offset) << 16) + (Sine12bit[Idx]/2 + offset);
        _DualSine12bit[Idx]  = ((_Sine12bit[Idx]/2 + offset) << 16) + (_Sine12bit[Idx]/2 + offset);
    }
    ADDR[0]=(uint32_t)&DualSine12bit;
    ADDR[1]=(uint32_t)&_DualSine12bit;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE );//使能PORTA通道时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE );//使能DAC通道时钟
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;// 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 	//模拟输入
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    DAC_InitStructure.DAC_Trigger=DAC_Trigger_T2_TRGO;	
    DAC_InitStructure.DAC_WaveGeneration=DAC_WaveGeneration_None;//不使用波形发生
    DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude=DAC_LFSRUnmask_Bit0;//屏蔽、幅值设置
    DAC_InitStructure.DAC_OutputBuffer=DAC_OutputBuffer_Enable ;//DAC1输出缓存关闭 BOFF1=1
    DAC_Init(DAC_Channel_1,&DAC_InitStructure);	 //初始化DAC通道1
    DAC_Init(DAC_Channel_2,&DAC_InitStructure);
    DAC_Cmd(DAC_Channel_1, ENABLE);  //使能DAC1
    DAC_Cmd(DAC_Channel_2, ENABLE);
    DAC_DMACmd(DAC_Channel_2, ENABLE);

    DMA_InitStructure.DMA_PeripheralBaseAddr = DAC_DHR12RD_Address;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&DualSine12bit;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
    DMA_InitStructure.DMA_BufferSize = sinesize;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

    NVIC_InitStructure.NVIC_IRQChannel = DMA2_Channel4_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级2级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
    NVIC_Init(&NVIC_InitStructure);

    DMA_ITConfig(DMA2_Channel4,DMA_IT_TC,ENABLE);
    DMA_Init(DMA2_Channel4, &DMA_InitStructure);
    DMA_Cmd(DMA2_Channel4, ENABLE);

}
 
__IO u8 PN=0xCA;
void DMA2_Channel4_5_IRQHandler(void)
{
    static u8 times=0;
    if(times == 4){ 
        PN = (PN<<1) | ((PN&0x01)^Abs_code);
        
        if(PN & 0x08){
            Abs_code = 1;
            Rela_code = !Rela_code;
            DMA2_Channel4->CMAR = ADDR[Rela_code];
        }else{
            Abs_code = 0;
        }
        DMA2->IFCR = DMA2_IT_TC4;
        times = 0;
        
    }else{
        DMA2->IFCR = DMA2_IT_TC4;
    }
    if(++times%2)
        CLK=!CLK;

}

