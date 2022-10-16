;/********************************************************************/
;/* aplusb.S: c=a+b  on Samsung S3C410A                              */
;/********************************************************************/                  

                PRESERVE8
Inheight 		equ 6
Inwidth  		equ 6
Outheight 		equ 4
Outwidth		equ 4
kernel      	equ 3
				AREA    CN, CODE, READONLY
				
				ENTRY
				mov sp,#600
				mov r4,#0			;i
				ldr r3,=Carry

OutLoop
				mov r5,#0			;j
				
				
InLoop
				mov r6,#0			;ki
		
				str r1,[r3],#4
				mov r1,#0
				ldr r0,=Barry

In2Loop			
				mov	r7,#0			;kj 			:

				

In3Loop
						
				mov r11,#Inheight
				push {r11}
				
				mul r10, r4 ,r11		;i*I_H

				add r12, r10,r5			;i*I_H+j
				mul r10, r6 ,r11		;ki*I_H
				
				add r11,r10,r12			;ki*I_H+j+i*I_H
				add r10,r11,r7			;ki*I_H+j+i*I_H+kj
				mov r8,#4
				mul r12,r10,r8			;4word
				
				ldr r8,=Aarry			;A_Adress
				
				add r10,r8,r12
				
				ldr r11,[r10]			;Anumber
				
				ldr r9,[r0],#4			;Bnumber
				mul r10,r11,r9
				
				pop {r11}
				
				add r1,r1,r10
				
				add r7,r7,#1
				cmp	r7,#kernel
				bne In3Loop
				add r6,r6,#1
				cmp	r6,#kernel
				bne In2Loop
				add r5,r5,#1
				cmp r5,#4
				bne	InLoop
				add r4,r4,#1
				cmp r4,#4
				bne	OutLoop
				str r1,[r3],#4
				nop
				nop

				
;				LTORG
				
Aarry      		DCD     0x23,0x25,0x27,0x85,0x86,0x87
				DCD     0x33,0x35,0x35,0x95,0x95,0x98
				DCD     0x44,0x45,0x44,0xA5,0xA6,0xA7   
				DCD 	0xD5,0xD6,0xD7,0x68,0x69,0x7A
				DCD 	0xFD,0xFF,0xFE,0x42,0x43,0x43
				DCD		0xEA,0xEB,0xEC,0x55,0x56,0x56
					
					
Barry			DCD      1,2,1
				DCD		 0,0,0
				DCD		 -1,-2,-1
					
Carry			DCD		0,0,0,0,0,0
				DCD		0,0,0,0,0,0
				DCD		0,0,0,0,0,0
				
			
                END
