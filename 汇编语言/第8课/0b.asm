.model tiny
.code
.startup
getkey:	mov ah,0bh
	int 21h
	or al,al	;al��0��
	jz getkey

   .exit 0
end