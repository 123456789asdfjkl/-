.model tiny;
.code;
.startup;

mov dx,offset fName ; �����ļ�
mov cx,0
mov ah,3ch
int 21h        
.exit 0           ;�˳�����

fName db 'd:\asm.txt',0h
fBuffer db 'Hello,world!'
end