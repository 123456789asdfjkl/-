.model tiny   		; 1 .model �洢ģʽαָ��
.code			; 2 .code �ζ���αָ��
.startup			; 3 .���򿪷�αָ��
           mov     dx,offset string   ; 4.ָ���ַ�����ƫ��
            mov    ah,9                    ; 5.
            int       21h                     ; 6.���ù��ܵ�����ʾ��Ϣ   
            mov ah,2
            mov dl,24h
            int 21h
.exit 0			 ; 7 .exit �������αָ��
string db  'Name: changjunlin',0dh,0ah,'Number: 201785085',0dh,0ah,'Phone: 18340896933',0dh,0ah,'Email:chang13579@mail.dlut.edu.cn',0dh,0ah,'$' ; 8. �����ַ���
end         			 ; ������
