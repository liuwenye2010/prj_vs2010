// console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>  
#include <stdarg.h>
#include <string.h> 
#include <Windows.h> 
#include <stdint.h> 


#include <stdio.h> // for printf 
#define DUMP(f_, ...) printf((f_), __VA_ARGS__)



#define InitShowProgress(MaxPos)  printf( "Downloading ... %3d%%", 0); fflush(stdout);
#define ShowProgress(curPos,MaxPos) printf( "\b\b\b\b%3d%%", (char) (((curPos) *100)/MaxPos) ); fflush(stdout);

int my_printf( const char *format, ... ); 
void sys_print   (const char * format, ... ); 
int my_sprintf_s(char * buffer, rsize_t bufsz,const char *format, ...); 
int call_vsscanf(char *tokenstring, char *format, ...)  ; 
int32_t test_hash();
int RangedRand( int range_min, int range_max ); 

static void _doa_records_callback(void *data); 

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 0 ; 
	int b = 1 ; 
	my_printf("my_printf the value is %d, %d \r\n",a, b);
	printf("printf the value is %d, %d \r\n",a, b);
	sys_print("sys_print the value is %d, %d \r\n",a, b);

   char  buffer[200], s[] = "computer", c = 'l';  
   int   i = 35, j;  
   float fp = 1.7320534f;  
#if 0  
   // Format and print various data:   
   j  = sprintf_s( buffer, 200,     "   String:    %s\n", s );  
   j += sprintf_s( buffer + j, 200 - j, "   Character: %c\n", c );  
   j += sprintf_s( buffer + j, 200 - j, "   Integer:   %d\n", i );  
   j += sprintf_s( buffer + j, 200 - j, "   Real:      %f\n", fp );  
   printf( "Output:\n%s\ncharacter count = %d\n", buffer, j );
#else 
   j  = my_sprintf_s( buffer, 200,     "  my_sprintf_s String:    %s\n", s );  
   j += my_sprintf_s( buffer + j, 200 - j, "  my_sprintf_s Character: %c\n", c );  
   j += my_sprintf_s( buffer + j, 200 - j, "  my_sprintf_s Integer:   %d\n", i );  
   j += my_sprintf_s( buffer + j, 200 - j, "  my_sprintf_s Real:      %f\n", fp ); 
  
   printf( "Output:\n%s\ncharacter count = %d\n", buffer, j );
#endif 
 
# if 0 
    char  tokenstring[] = "15 12 14...";  
    char  ss[81];  
    char  cc;  
    int   ii;  
    float ffp;  
  
    // Input various data from tokenstring:  
    // max 80 character string:  
    call_vsscanf(tokenstring, "%80s", ss);   
    call_vsscanf(tokenstring, "%c", &cc);  
    call_vsscanf(tokenstring, "%d", &ii);  
    call_vsscanf(tokenstring, "%f", &ffp);  
  
    // Output the data read  
    printf("String    = %s\n", ss);  
    printf("Character = %c\n", cc);  
    printf("Integer:  = %d\n", ii);  
    printf("Real:     = %f\n", ffp);

#endif 

    
	InitShowProgress(100); 
	ShowProgress(1,0,0,100); 
	//Sleep(1000); 
	//ShowProgress(2,0,0,100); 
	//Sleep(1000); 
	//ShowProgress(3,0,0,100); 
	//Sleep(1000); 
	//ShowProgress(4,0,0,100); 

#if 0 
    printf("test_hash in windows\r\n"); 
	test_hash();
#endif 


	for (int ri=0; ri<100;ri++)
	{
		//RangedRand(-180,180); 
		_doa_records_callback(NULL);
	}
	



	getchar(); 

}


/*
int snprintf( char *restrict buffer, size_t bufsz, 
               const char *restrict format, ... ); 
(4)  (since C99)  

*/ 

/* 

int sprintf_s(char *restrict buffer, rsize_t bufsz,
               const char *restrict format, ...); 
(7)  (since C11)  

*/ 

int my_sprintf_s(char * buffer, rsize_t bufsz,const char *format, ...)
{
 
  va_list ap;
  int str_l;
  va_start(ap, format);
  //str_l = vsprintf_s(buffer, bufsz, format, ap); // since C11 
  str_l = vsnprintf(buffer, bufsz, format, ap); // since c99 
  

  va_end(ap);
  return str_l;

}






int my_printf( const char *format, ... )
{
  va_list ap;
  int str_l;
  va_start(ap, format);
  str_l =vprintf(format, ap);  //call vprintf() instead of printf() using the variable arguments "varargs" capabilities of C.
  va_end(ap);
  return str_l;
}




void sys_print   (const char * format, ... )
{
  const int MAX_BUF_SIZE = 2000;
  char szInfo[MAX_BUF_SIZE]="";
  va_list va;
  va_start(va, format);

  int nShift = strlen(szInfo);


  vsprintf_s(szInfo + nShift,MAX_BUF_SIZE-nShift,format, va);
 
 


  printf(szInfo);
  //OutputDebugStringA(szInfo);  //print to debugview

  va_end(va); 
}




// crt_vsscanf.c  
// compile with: /W3  
// This program uses vsscanf to read data items  
// from a string named tokenstring, then displays them.  
  
 
  
int call_vsscanf(char *tokenstring, char *format, ...)  
{  
    int result;  
    va_list arglist;  
    va_start(arglist, format);  
    //result = vsscanf(tokenstring, format, arglist);  // VS2010 can't fully support the C99, we should use the VS2013 at least 
    va_end(arglist);  
    return result;  
}  
  

  
typedef uint16_t word;
typedef uint32_t dword;

#define _WINDOWS
#if defined(_WINDOWS) 
#define __PACKED__  
#else
#define __PACKED__ __attribute__((packed))
#endif

struct i2c_message_s
{
	int32_t   cmd:6;			// the command
	uint32_t  err:1;			// error in message
	uint32_t  repl:1;			// done - command completed
	uint32_t  blk:8;			// block nr
	uint32_t  len:16;			// total length of mesage (in bytes)
	dword crc;			// crc over message
} __PACKED__ ;			//



 int endianess_is_little()
{
    unsigned int endianness = 1;
    return ((char*)(&endianness))[0]==1;
}
/*
* Convert a 2-byte number from a ByteOrder into another ByteOrder.
*/
 uint16_t byte_swap_ushort(uint16_t i)
{
  return ((i>>8)&0xff)+((i << 8)&0xff00);
}

static uint16_t to_little_endia_us(uint16_t i)
{
  if(!endianess_is_little())
    return byte_swap_ushort(i);
  else
    return i;
}


 /*
* Convert a 4-byte number from a ByteOrder into another ByteOrder.
*/
static uint32_t  byte_swap_ulong(uint32_t i)
{
  return((i&0xff)<<24)+((i&0xff00)<<8)+((i&0xff0000)>>8)+((i>>24)&0xff);
}


static uint32_t to_little_endia_ul(uint32_t i)
{
  if(!endianess_is_little())
    return byte_swap_ulong(i);
  else
    return i;
}


 uint32_t hash(const void *dat,uint32_t n)
{
  const word *d=(const word *)dat;
  uint32_t s1=0xffff;
  uint32_t s2=0xffff;
  n=n/sizeof(short); //?
  //printf("sizeof(short) == %d\r\n",sizeof(short)); 
  while(n)
  {
    uint32_t l=n>359?359:n;
    n-=l;
    do {
      s2+=s1+=*d++;
    } while (--l);
    s1=(s1&0xffff)+(s1>>16);
    s2=(s2&0xffff)+(s2>>16);
  }
  /* Second reduction step to reduce sums to 16 bits */
  s1=(s1&0xffff)+(s1>>16);
  s2=(s2&0xffff)+(s2>>16);
  return (s2<<16)|s1;
}

#if 0 
# define ERROR_CODE(a)	error(ERROR_##a,__FILE__,__LINE__)
int error(int err,const char *file,int line)
  {
  KPRINT0("ERROR: %d %s %d\n",err, file, line);
  spi_protect(SW_PROTECT);
#if defined CONFIG_LIVE_I2C_FLASH_LEGACY
  i2cs_code=TRANSFER_STATE_FATAL;
#else
  i2c.hdr.err=1;
  i2c.hdr.cmd=err;
  i2c.hdr.blk=cblk;
  i2c.hdr.repl=1;
#endif
  return err;
  }

#endif 

#define ERROR_BLOCK_NR		-1
#define ERROR_CHECKSUM		-2
#define ERROR_LENGTH		-3
#define ERROR_TIMEOUT		-4
#define ERROR_NSUPP		-5
#define ERROR_NPROT		-6
#define ERROR_ERASE		-7
#define ERROR_WRITE		-8
#define ERROR_VERIFY		-9
#define ERROR_INVALID_CMD	-10
#define ERROR_NOTHING_TO_DO	-11
#define ERROR_I2C_INTERNAL	-20


/* Static memory */
struct state_mem_s {
  uint32_t                 i2c_blknr                ;
  uint32_t         bEraseChip               ;
  int32_t                  is_partial_img           ;
  word                 partial_offset           ;
  int32_t                  is_dual_img              ;
};

#define SYNA_AUDIO_SPI_NAME_LEN 16
union spi_name_u		{word buf[SYNA_AUDIO_SPI_NAME_LEN/2]; uint8_t name[SYNA_AUDIO_SPI_NAME_LEN];};

struct i2c_verify_img_cmd_s	{ struct i2c_message_s hdr; word header; word first; word last; word padding; dword magic; dword autom;} __PACKED__;
struct i2c_verify_img_rpl_s	{ struct i2c_message_s hdr; dword status; } __PACKED__;
struct i2c_ping_rpl_s		{ struct i2c_message_s hdr; dword id; union spi_name_u spi_name;} PACKED;


struct state_memory_s {
  struct i2c_verify_img_cmd_s pWrBuffer;
  struct i2c_ping_rpl_s       pRdBuffer;
  struct state_mem_s          stat_mem ;
};

#define ALIGNMENT_SIZE       (sizeof(long))

#define BUFFER_SIZE          (ALIGNMENT_SIZE+sizeof(struct state_memory_s))



int32_t test_hash()
{

	struct i2c_message_s msg;
	uint32_t tlen;

	tlen= 8; 
	msg.blk =  0; 
	msg.len =  to_little_endia_us((uint16_t)tlen);
	msg.cmd = 0; 
	msg.err = 0; 
	msg.repl =0;  
	msg.crc = 0; //should be clear 
    msg.crc =  to_little_endia_ul(hash(&msg,tlen));

    printf("msg.crc 0x%08x \r\n", msg.crc);

 
	tlen = 8; 
	msg.blk =  0; 
	msg.len =  8; // to_little_endia_us((uint16_t)tlen);
	msg.cmd = 0; 
	msg.err = 0; 
	msg.repl =0;  
	msg.crc = 0; //should be clear 
    msg.crc =  to_little_endia_ul(hash(&msg,tlen));

    printf("msg.crc 0x%08x \r\n", msg.crc);


	msg.blk =  0; 
	msg.len =  8; // to_little_endia_us((uint16_t)tlen);
	msg.cmd =  ERROR_CHECKSUM; 
	msg.err =  1; 
	msg.repl = 1;  
	msg.crc = 0; //should be clear 

	uint8_t *u8_msg =(uint8_t*)&msg; 
	printf("u8_msg[%d] == %u \r\n", 0, u8_msg[0]); 
	printf("u8_msg[%d] == %u \r\n", 1, u8_msg[1]); 
	printf("u8_msg[%d] == %u \r\n", 2, u8_msg[2]); 
	printf("u8_msg[%d] == %u \r\n", 3, u8_msg[3]); 

	    printf("BUFFER_SIZE == %d\r\n",BUFFER_SIZE);

	return 0; 

}

void SimpleRandDemo( int n )
{
   // Print n random numbers.
   int i;
   for( i = 0; i < n; i++ )
      printf( "  %6d\n", rand() );
}

void RangedRandDemo( int range_min, int range_max, int n )
{
   // Generate random numbers in the half-closed interval
   // [range_min, range_max). In other words,
   // range_min <= random number < range_max
   int i;
   for ( i = 0; i < n; i++ )
   {
      int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min)
            + range_min;
      printf( "  %6d\n", u);
   }
}


int RangedRand( int range_min, int range_max )
{
   // Generate random numbers in the half-closed interval
   // [range_min, range_max). In other words,
   // range_min <= random number < range_max
   int i;
   int n= 1;
   int u  =0; 
   for ( i = 0; i < n; i++ )
   {
       u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min)
            + range_min;
      printf( "  %6d\n", u);
   }
   
   return  u;  
}



#if 1

#define  DOA_BUFFER_SIZE      20  
static  int32_t  inst_doa_buffer[DOA_BUFFER_SIZE] = {0}; 
static  int32_t  target_speech_doa_buffer[DOA_BUFFER_SIZE] = {0};
static  int32_t  inst_doa_average_buffer[DOA_BUFFER_SIZE] = {0}; 
static  int32_t  target_speech_doa_average_buffer[DOA_BUFFER_SIZE] = {0};
static  uint32_t  idx_doa =0 ; 


static void _doa_records_callback(void *data)
{
    
     int32_t  inst_DOA ; 
     int32_t  target_speech_DOA ; 
     int32_t  i,j; 
     int32_t  start_idx = 13;  
     int32_t  stop_idx = 16; 
     int32_t  inst_doa_avg = 0;  
     int32_t  targ_doa_avg = 0; 

    /* timer callback 50ms , readback the DOA paramter back , push to FIFO (20 units) , calculate the  average */ 

    ///* step 1  golem::sendcmd CAPT 30 SPATIAL_SEP2_CMD_GET_INTERNAL_STATE {} */
    //COMMAND_OF_SIZE(3) cmd;
    //cmd.num_32b_words = 3;
    //cmd.command_id    = 0x142;
    //cmd.reply         = 0;
    //cmd.app_module_id = _ID('C','A','P','T') | 30 ;
    //sos_signal(_ID('C','A','P','T'), SIG_CMD, (void *)sos_virt_to_phys_stk(&cmd));
    //if (cmd.num_32b_words > 0) {
    //    inst_DOA = cmd.data[0];
    //    target_speech_DOA = cmd.data[2]; 
    //} else {
    //    kprint("DOA_cb:0x%x\n",cmd.num_32b_words);
    //   return cmd.num_32b_words;
    //}

#define _DEBUG_DOA  1 
#if _DEBUG_DOA  
	 inst_DOA = RangedRand(-180,180)*8388608; 
	 //DUMP("inst_DOA is %d \r\n", inst_DOA); 
	 target_speech_DOA = RangedRand(-180,180)*8388608; 
	 //DUMP("target_speech_DOA is %d \r\n", target_speech_DOA); 
	 
#endif 



   /* step 2 insert to circular buffer */  
    if( idx_doa < DOA_BUFFER_SIZE  ) 
    { 
		//DUMP("inst_DOA; %d\n", inst_DOA); 
        inst_doa_buffer[idx_doa]           =inst_DOA; 
		//DUMP("inst_doa_buffer %d\n", inst_doa_buffer[idx_doa]); 
        target_speech_doa_buffer[idx_doa]  = target_speech_DOA;   
		//DUMP("inst_doa_buffer[%d]:%d \r\n", idx_doa, inst_doa_buffer[idx_doa]);
        idx_doa++ ; 
		
    }
    else
    {
        idx_doa =  0 ; 
    }

#if 0 
	DUMP("inst_doa_buffer: "); 
	for (int k1 =0; k1 < DOA_BUFFER_SIZE; k1++)
	{
		DUMP("%d,",inst_doa_buffer[k1]); 
	}
    DUMP("\n");
#endif    

   /* reshape the circular buffer */  

    for(i =0; i< DOA_BUFFER_SIZE; i++ )
    {
	   int avg_idx = (idx_doa + i + 1)% DOA_BUFFER_SIZE; 
	   //DUMP("inst_doa_buffer[%d]= %d \n",avg_idx,  inst_doa_buffer[avg_idx]); 
	   
       inst_doa_average_buffer[i]           =   inst_doa_buffer[avg_idx] >> 23 ; 
	    //DUMP("inst_doa_average_buffer[%d]= %d \n",i,  inst_doa_average_buffer[i]);
       target_speech_doa_average_buffer[i]  =   target_speech_doa_buffer[avg_idx] >>23 ; 
    }

	DUMP("inst_doa_average_buffer: "); 
	for (int k2 =0; k2 < DOA_BUFFER_SIZE; k2++)
	{
		DUMP("%d,",inst_doa_average_buffer[k2]); 
	}
    DUMP("\n"); 

   /* step 4 calculate the average , start index  to stop index  */

   inst_doa_avg = 13;
   targ_doa_avg = 16;  
   for (j=start_idx; j<=stop_idx; j++ ) 
   {
       
       if( inst_doa_average_buffer[j] < 180 && inst_doa_average_buffer[j] > -180   )
       {       
         inst_doa_avg = inst_doa_avg + inst_doa_average_buffer[j];
       }

       if( target_speech_doa_average_buffer[j] < 180 && target_speech_doa_average_buffer[j] > -180   )
       {       
         targ_doa_avg = targ_doa_avg + target_speech_doa_average_buffer[j];
       }
   }

       inst_doa_avg  = inst_doa_avg / (stop_idx - start_idx + 1);
       targ_doa_avg  = targ_doa_avg / (stop_idx - start_idx + 1);
	   DUMP("inst_doa_avg is %d \r\n", inst_doa_avg); 
	   DUMP("targ_doa_avg is %d \r\n", targ_doa_avg);

}

#endif 