.model tiny   		; 1 .model �洢ģʽαָ��
.code			; 2 .code �ζ���αָ��
.startup			; 3 .���򿪷�αָ��
   mov al,0fh	;�ṩ����AL
	call htoasc	;�����ӳ���
.exit 0			 ; 7 .exit �������αָ��

htoasc proc
and al,0fh	;ֻȡal�ĵ�4λ
	or al,30h	;al��4λ���3
	cmp al,39h	;��0��9������0Ah��0Fh
	jbe htoend
	add al,7	;��0Ah��0Fh������7
htoend:ret
htoasc endp

string db  'Hello,World!',0dh,0ah,'$' ; 8. �����ַ���
end         			 ; ������
