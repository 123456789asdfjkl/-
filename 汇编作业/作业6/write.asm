.model tiny
.stack
.data
	string1 db 'Name:changjunlin',0dh,0ah,'Number:201785085',0dh,0ah,'Phone:18340896933',0dh,0ah,'Email:chang13579@mail.dlut.edu.cn',0dh,0ah,'$'
	fName db 'd:\myinfo.txt',0h
.code
.startup
	mov dx,offset fName ; �����ļ�
	mov cx,0
	mov ah,3ch
	int 21h 

	mov ah,3dh          ;���ļ�
    mov al,03
    mov dx,offset fName
    int 21h
    push ax             ;�����ļ����

    mov bx,ax
    mov cx, 90
    lea dx,string1
    mov ah,40h
    int 21h             ;д�ļ�

    pop bx              ;�����ļ����

    mov ah,3eh          ;�ر��ļ�
    int 21h

.exit 0
end