
//=======================================================
//  This code is generated by Terasic System Builder
//=======================================================

module pcihello(

	//////////// CLOCK //////////
	CLOCK_50, 	// BANK 4
	CLOCK2_50, 	// BANK 7
	CLOCK3_50, 	// BANK 3A

	//////////// LED (High Active) //////////
	LEDG,
	LEDR,

	//////////// KEY (Active Low) //////////
	KEY,

	// switches
   SW,
	
	//////////// SEG7 (Low Active) //////////
	HEX0,
	HEX1,
	HEX2,
	HEX3,
	HEX4,
	HEX5,
	HEX6,
	HEX7,

	//////////// PCIe //////////
	PCIE_PERST_N,
	PCIE_REFCLK_P,
	PCIE_RX_P,
	PCIE_TX_P,
	PCIE_WAKE_N,

	//////////// Fan Control //////////
	FAN_CTRL,

	/// LCD Control
	LCD_DATA,
	LCD_EN,
	LCD_RW,
	LCD_RS,
	LCD_ON,
);

//=======================================================
//  PARAMETER declarations
//=======================================================


//=======================================================
//  PORT declarations
//=======================================================

//////////// CLOCK //////////
input 		          		CLOCK_50;
input 		          		CLOCK2_50;
input 		          		CLOCK3_50;

//////////// LED (High Active) //////////
output		     [8:0]		LEDG;
output		    [17:0]		LEDR;

//////////// KEY (Active Low) //////////
input 		     [3:0]		KEY;
input            [17:0]	   SW;

//////////// SEG7 (Low Active) //////////
output		     [6:0]		HEX0;
output		     [6:0]		HEX1;
output		     [6:0]		HEX2;
output		     [6:0]		HEX3;
output		     [6:0]		HEX4;
output		     [6:0]		HEX5;
output		     [6:0]		HEX6;
output		     [6:0]		HEX7;

//////////// PCIe //////////
input 		          		PCIE_PERST_N;
input 		          		PCIE_REFCLK_P;
input 		     [1:0]		PCIE_RX_P;
output		     [1:0]		PCIE_TX_P;
output		          		PCIE_WAKE_N;

//////////// Fan Control //////////
inout 		          		FAN_CTRL;

/// LCD COntrol


output [7:0] LCD_DATA;
output LCD_EN;
output LCD_RW;
output LCD_RS;
output LCD_ON;


wire [31:0] lcdbus;
wire [31:0] ldis;
wire [31:0]	rdis;
wire [31:0]	swi;
wire [31:0]	bpush;
wire [31:0]	rleds;
wire [31:0]	gleds;
//=======================================================
//  REG/WIRE declarations
//=======================================================

// wire [31:0] hexbus;
// wire [15:0] inbus;


//=======================================================
//  Structural coding
//=======================================================

    pcihellocore u0 (
        .pcie_hard_ip_0_rx_in_rx_datain_0       (PCIE_RX_P[0]),       //     pcie_hard_ip_0_rx_in.rx_datain_0
        .pcie_hard_ip_0_tx_out_tx_dataout_0     (PCIE_TX_P[0]),     //    pcie_hard_ip_0_tx_out.tx_dataout_0
        .pcie_hard_ip_0_powerdown_pll_powerdown (PCIE_WAKE_N), // pcie_hard_ip_0_powerdown.pll_powerdown
        .pcie_hard_ip_0_powerdown_gxb_powerdown (PCIE_WAKE_N), //                         .gxb_powerdown
        .pcie_hard_ip_0_refclk_export           (PCIE_REFCLK_P),           //    pcie_hard_ip_0_refclk.export
        .pcie_hard_ip_0_pcie_rstn_export        (PCIE_PERST_N),
        //.hexport_external_connection_export     (hexbus),     // hexport_external_connection.export
        //.inport_external_connection_export      (inbus)       //  inport_external_connection.export
			.pio_0_lcd_external_connection_export(lcdbus),
			.pio_1_display_l_external_connection_export(ldis),
			.pio_2_display_r_external_connection_export(rdis),
			.pio_3_switches_external_connection_export(swi),
			.pio_4_push_b_external_connection_export(bpush),
			.pio_5_r_leds_external_connection_export(rleds),
			.pio_6_g_leds_external_connection_export(gleds),


    );
	 


	//////////// FAN Control //////////
assign FAN_CTRL = 1'b0; // turn off FAN
/*
assign HEX0 = hexbus[ 6: 0];
assign HEX1 = hexbus[14: 8];
assign HEX2 = hexbus[22:16];
assign HEX3 = hexbus[30:24];

assign inbus = SW[15:0];
*/

assign LCD_DATA = lcdbus[7:0];
assign LCD_EN = lcdbus[8];
assign LCD_RW = lcdbus[9];
assign LCD_RS = lcdbus[10];
assign LCD_ON = lcdbus[11];

assign HEX0 = ldis[6:0];
assign HEX1 = ldis[13:7];
assign HEX2 = ldis[20:14];
assign HEX3 = ldis[27:21];

assign HEX4 = rdis[6:0];
assign HEX5 = rdis[13:7];
assign HEX6 = rdis[20:14];
assign HEX7 = rdis[27:21];

assign bpush[3:0] = KEY;

assign swi[17:0] = SW;

assign LEDG = gleds[8:0];
assign LEDR = rleds[17:0];

endmodule
