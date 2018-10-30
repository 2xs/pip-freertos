OUTPUT_FORMAT("binary")
ENTRY(_start)

physbase = 0x00700000;

SECTIONS
{
 	.text 0x00700000:
	{
	    code = .;
	    __text_start =  ABSOLUTE(.);
	    *(.text.entry)
	    *(.text)
	    *(.text.last)
	    *(.text.*)
	    . = ALIGN(4);
		*(.rodata)
		*( .rodata.*)
 	    __text_end =  ABSOLUTE(.);
  		. = ALIGN(4096);

	}	/* Read-write data (initialised) */


    .partition1 : ALIGN(4096)
    {
        _partition1 = . ;
        *(.partition1)
        . = ALIGN(0x40000);
        _epartition1 = . ;
    }

    .partition2 : ALIGN(4096)
    {
        _partition2 = . ;
        *(.partition2)
        . = ALIGN(0x40000);
        _epartition2 = . ;
    }

    .partition3 : ALIGN(4096)
    {
        _partition3 = . ;
        *(.partition3)
        . = ALIGN(0x40000);
        _epartition3 = . ;
    }
    .partition4 : ALIGN(4096)
    {
        _partition4 = . ;
        *(.partition4)
        . = ALIGN(0x40000);
        _epartition4 = . ;
    }
    .partition5 : ALIGN(4096)
    {
        _partition5 = . ;
        *(.partition5)
        . = ALIGN(0x40000);
        _epartition5 = . ;
    }
    .data :
	{
 		__data_start = ABSOLUTE(.);
  		__data_lma = LOADADDR(.data);
  		__data_vma =  ABSOLUTE(.);
 		*(.data)
 		*(.data.*)
 		__data_end = ABSOLUTE(.);
 		. = ALIGN(4096);
 	}

	/* Read-write data (uninitialised) */
 	.bss :
	{
    	__bss_start =  ABSOLUTE(.);
    	*(.bss)
     	*(COMMON)
    	__bss_end =  ABSOLUTE(.);
   		. = ALIGN(1024);
 	}

	/* stack used before the scheduler starts */
 	.boot_stack :
	{
		/* 2K for the boot stack.  This could be avoided by using the same RAM
		as used by the FreeRTOS system/interrupt stack. */
		. += 2048;
    	__stack_for_main = ABSOLUTE( . );
   		. = ALIGN(1024);
 	}

	/*exception unwinding and source language information */
	.eh_frame : { KEEP (*(.eh_frame)) . = ALIGN(4); }

	/* function exports */
 	.drectve : { KEEP (*(.drectve)) }

   	.comment : { *(.comment) }
  	.inthandler :
  	{
		inthandler = .;
		_inthandler = .;
		__inthandler = .;
		*(.inthandler)
		. = ALIGN(4096);
  	}
  end = .; _end = .; __end = .;

}
