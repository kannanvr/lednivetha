/*
void rotate_left(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,bool);
void rotate_right(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,bool);
void blink_barscroll_fm_left(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,bool);
void blink_barscroll_fm_right(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,bool);
void cyclic_blink(unsigned char,unsigned char,unsigned char,bool);
void multi_blink(unsigned char,unsigned char,unsigned char,bool);

void barscroll_fm_left(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,bool);
void barscroll_fm_right(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,bool);
void barscroll_back_n_forth(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,bool);

void fill_left_blind(unsigned char,unsigned char,unsigned char,unsigned char,bool);
void fill_right_blind(unsigned char,unsigned char,unsigned char,unsigned char,bool);

void fill_fm_middle(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,bool);
void fill_fm_ends(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,bool);
void fill_back_n_forth(unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,bool);
void fill_fm_left(unsigned char,unsigned char,unsigned char,unsigned char,bool);
void fill_fm_right(unsigned char,unsigned char,unsigned char,unsigned char,bool);
//========================================//=========================================
void fill_fm_left(unsigned char bg_color,unsigned char color,unsigned char speed,unsigned char count,bool clr)
{
	for(unsigned char i=0;i<count;i++)
	{
		clear_display(bg_color);
		for(unsigned char i=0;i<50;i++)
			{
			set_block_color(i,1,color,0);
			output_grb(buf,150);
			_delay_ms(speed);
			}
	}
		if(clr ==true)
			{
			_delay_ms(hold_time);
			clear_display(0);
			}
}
//=========================================
void fill_fm_right(unsigned char bg_color,unsigned char color,unsigned char speed,unsigned char count,bool clr)
{
	for(unsigned char i=0;i<count;i++)
	{
		clear_display(bg_color);
		for(unsigned char i=0;i<50;i++)
			{
			set_block_color((49-i),1,color,1);
			output_grb(buf,150);
			_delay_ms(speed);
			}
	}
		if(clr ==true)
			{
			_delay_ms(hold_time);
			clear_display(0);
			}
}
//=========================================
void fill_back_n_forth(unsigned char bg_color,unsigned char color1,unsigned char color2,unsigned char speed,unsigned char count,bool clr)
{
	for(unsigned char j=0;j<count;j++)
	{
		clear_display(bg_color);
		for(unsigned char i=0;i<50;i++)
			{
			set_block_color(i,1,color1,0);
			output_grb(buf,150);
			_delay_ms(speed);
			}
		clear_display(bg_color);
		for(unsigned char i=0;i<50;i++)
			{
			set_block_color((49-i),1,color2,1);
			output_grb(buf,150);
			_delay_ms(speed);
			}
	}
		if(clr ==true)
			{
			_delay_ms(hold_time);
			clear_display(0);
			}
}
//=========================================
void fill_left_blind(unsigned char bg_color,unsigned char color,unsigned char speed,unsigned char count,bool clr)
{
	for(unsigned char i=0;i<count;i++)
	{
		clear_display(bg_color);
		for(unsigned char k=0;k<10;k++)
			{
		    for(unsigned char h=0;h<50;h+=10)
			set_block_color(h+k,1,color,0);
			output_grb(buf,150);
			_delay_ms(speed);
			}
	}
		if(clr ==true)
			{
			_delay_ms(hold_time);
			clear_display(0);
			}
}
//=========================================
void fill_right_blind(unsigned char bg_color,unsigned char color,unsigned char speed,unsigned char count,bool clr)
{
	for(unsigned char i=0;i<count;i++)
	{
		clear_display(bg_color);
		for(unsigned char k=0;k<10;k++)
			{
		    for(unsigned char h=0;h<50;h+=10)
			set_block_color((49-k)+h,1,color,1);
			output_grb(buf,150);
			_delay_ms(speed);
			}
	}
		if(clr ==true)
			{
			_delay_ms(hold_time);
			clear_display(0);
			}
}
//=========================================
void barscroll_fm_left(unsigned char bg_color,unsigned char color,unsigned char num,unsigned char speed,unsigned char count,bool clr)
{
	for(unsigned char j=0;j<count;j++)
	{
		for(unsigned char i=0;i<50;i++)
		{
			clear_display(bg_color);
			set_block_color(i,num,color,0);
			output_grb(buf,150);
			_delay_ms(speed);
		}
	}
		if(clr ==true)
			{
			_delay_ms(hold_time);
			clear_display(0);
			}
}
//=========================================
void barscroll_fm_right(unsigned char bg_color,unsigned char color,unsigned char num,unsigned char speed,unsigned char count,bool clr)
{
	for(unsigned char j=0;j<count;j++)
	{
		for(unsigned char i=0;i<50;i++)
		{
			clear_display(bg_color);
			set_block_color((49-i),num,color,1);
			output_grb(buf,150);
			_delay_ms(speed);
		}
	}
		if(clr ==true)
			{
			_delay_ms(hold_time);
			clear_display(0);
			}
}
//=========================================
void fill_fm_ends(unsigned char bg_color,unsigned char color1,unsigned char color2,unsigned char speed,unsigned char count,bool clr)
{
	for(unsigned char i=0;i<count;i++)
	{
		clear_display(bg_color);
		for(unsigned char i=0;i<25;i++)		//make i<50 if overwrite is required
			{
			set_block_color(i,1,color1,0);
			set_block_color((49-i),1,color2,1);
			output_grb(buf,150);
			_delay_ms(speed);
			}
	}
		if(clr ==true)
			{
			_delay_ms(hold_time);
			clear_display(0);
			}
}
//=========================================
void fill_fm_middle(unsigned char bg_color,unsigned char color1,unsigned char color2,unsigned char speed,unsigned char count,bool clr)
{
	for(unsigned char i=0;i<count;i++)
	{
		clear_display(bg_color);
		for(unsigned char i=0;i<25;i++)
			{
			set_block_color((24-i),1,color1,1);
			set_block_color(25+i,1,color2,0);
			output_grb(buf,150);
			_delay_ms(speed);
			}
	}
		if(clr ==true)
			{
			_delay_ms(hold_time);
			clear_display(0);
			}
}
//========================================
void barscroll_back_n_forth(unsigned char bg_color,unsigned char color1,unsigned char color2,unsigned char num,unsigned char speed,unsigned char count,bool clr)
{
	for(unsigned char j=0;j<count;j++)
	{
		for(unsigned char i=0;i<51;i++)
		{
			clear_display(bg_color);
			set_block_color(i,num,color1,0);
			output_grb(buf,150);
			_delay_ms(speed);
		}
		for(unsigned char i=0;i<51;i++)
		{
			clear_display(bg_color);
			set_block_color((49-i),num,color2,1);
			output_grb(buf,150);
			_delay_ms(speed);
		}
	}
		if(clr ==true)
			{
			_delay_ms(hold_time);
			clear_display(0);
			}
}
//========================================
void cyclic_blink(unsigned char bg_color,unsigned char speed,unsigned char count,bool clr)
{
	for(unsigned char color=1;color<8;color++)
	if(color !=bg_color)blink(bg_color,color,speed,count,clr);
}	
//========================================
void multi_blink(unsigned char bg_color,unsigned char speed,unsigned char count,bool clr)
{
	for(unsigned char i=0;i<count;i++)
	{
	for(unsigned char color=1;color<8;color++)
	if(color !=bg_color)blink(bg_color,color,speed,1,clr);
	}
}
//=========================================
void blink_barscroll_fm_left(unsigned char bg_color,unsigned char color,unsigned char num,unsigned char speed,unsigned char count,bool clr)
{
	for(unsigned char j=0;j<count;j++)
	{
		for(unsigned char i=0;i<50;i++)
		{
			clear_display(bg_color);
			set_block_color(i,num,color,0);
			output_grb(buf,150);
			_delay_ms(100);
			clear_display(bg_color);
			_delay_ms(100);
			set_block_color(i,num,color,0);
			output_grb(buf,150);
			_delay_ms(100);
		}
	}
		if(clr ==true)
			{
			_delay_ms(hold_time);
			clear_display(0);
			}
}
//=========================================
void blink_barscroll_fm_right(unsigned char bg_color,unsigned char color,unsigned char num,unsigned char speed,unsigned char count,bool clr)
{
	for(unsigned char j=0;j<count;j++)
	{
		for(unsigned char i=0;i<50;i++)
		{
			clear_display(bg_color);
			set_block_color((49-i),num,color,1);
			output_grb(buf,150);
			_delay_ms(100);
			clear_display(bg_color);
			_delay_ms(100);
			set_block_color((49-i),num,color,1);
			output_grb(buf,150);
			_delay_ms(100);
		}
	}
		if(clr ==true)
			{
			_delay_ms(hold_time);
			clear_display(0);
			}
}
//==========================================
//this module needs to be checked
//==========================================	
void rotate_left(unsigned char color1,unsigned char color2,unsigned char color3,
unsigned char color4,unsigned char color5,unsigned char speed,unsigned char count,bool clr)
{
	unsigned char temp=0;
	set_block_color(0,10,color1,0);
	set_block_color(10,25,color2,0);
	set_block_color(20,10,color3,0);
	set_block_color(30,10,color4,0);
	set_block_color(40,10,color5,0);
	for(unsigned char k=0;k<count;k++)
	{
	for(unsigned char j=0;j<5;j++)
		{
		for(unsigned char i=0;i<10;i++)
			{
			output_grb(buf,150);
			_delay_ms(speed);
			set_block_color((49-i),1,color1,1);
			set_block_color((39-i),1,color5,1);
			set_block_color((29-i),1,color4,1);
			set_block_color((19-i),1,color3,1);
			set_block_color((9-i),1,color2,1);
			}
			temp=color1;
			color1=color2;
			color2=color3;
			color3=color4;
			color4=color5;
			color5=temp;
		}
	}
}	
*/
