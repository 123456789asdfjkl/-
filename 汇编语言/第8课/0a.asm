.model tiny
.code
.startup
	mov dx,offset buffer
	mov ah,0ah
	int 21h
   .exit 0
buffer	db 81 ;���建����
;��1���ֽ�����������������ַ���
	db 0	;���ʵ��������ַ���
	db 81 dup(0)	;���������ַ���
end