.model tiny   		; 1 .model �洢ģʽαָ��
.code			; 2 .code �ζ���αָ��
.startup			; 3 .���򿪷�αָ��
getkey:	
    mov ah,01h	;���ܺţ�ah��01h
	int 21h	;���ܵ���
	cmp al,'Y'	;������ڲ���al
	je yeskey	;�ǡ�Y��
	cmp al,'N'
	je nokey	;�ǡ�N��
	jne getkey
yeskey:  mov dx,offset str1
         jmp show
nokey:	  mov dx,offset str2
show:    mov ah,9
         int 21h

.exit 0			 ; 7 .exit �������αָ��
str1 db  'Pressed Y',0dh,0ah,'$' ; 8. �����ַ���
str2 db  'Pressed N',0dh,0ah,'$' ; 8. �����ַ���
end         			 ; ������
