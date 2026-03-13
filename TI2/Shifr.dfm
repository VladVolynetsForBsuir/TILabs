object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'TI_2'
  ClientHeight = 700
  ClientWidth = 1100
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  WindowState = wsMaximized
  TextHeight = 15
  object lblStartReg: TLabel
    Left = 24
    Top = 24
    Width = 328
    Height = 31
    Caption = #1053#1072#1095#1072#1083#1100#1085#1086#1077' '#1089#1086#1089#1090#1086#1103#1085#1080#1077' '#1088#1077#1075#1080#1089#1090#1088#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object lblKey: TLabel
    Left = 24
    Top = 108
    Width = 183
    Height = 31
    Caption = #1050#1083#1102#1095' ('#1076#1074#1086#1080#1095#1085#1099#1081')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object lblSource: TLabel
    Left = 24
    Top = 298
    Width = 292
    Height = 31
    Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1092#1072#1081#1083' ('#1076#1074#1086#1080#1095#1085#1099#1081')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object lblResult: TLabel
    Left = 560
    Top = 298
    Width = 226
    Height = 31
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090' ('#1076#1074#1086#1080#1095#1085#1099#1081')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object edtStartReg: TEdit
    Left = 24
    Top = 61
    Width = 1050
    Height = 39
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnChange = edtStartRegChange
  end
  object memoKey: TMemo
    Left = 24
    Top = 145
    Width = 1050
    Height = 140
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object memoSource: TMemo
    Left = 24
    Top = 335
    Width = 500
    Height = 230
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object memoResult: TMemo
    Left = 560
    Top = 335
    Width = 514
    Height = 230
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 3
  end
  object btnOpen: TButton
    Left = 24
    Top = 590
    Width = 240
    Height = 41
    Caption = #1054#1058#1050#1056#1067#1058#1068' '#1060#1040#1049#1051
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = btnOpenClick
  end
  object btnShifrDeshifr: TButton
    Left = 24
    Top = 645
    Width = 506
    Height = 41
    Caption = #1064#1048#1060#1056#1054#1042#1040#1058#1068' / '#1044#1045#1064#1048#1060#1056#1054#1042#1040#1058#1068
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = btnShifrDeshifrClick
  end
  object btnSave: TButton
    Left = 560
    Top = 590
    Width = 300
    Height = 41
    Caption = #1057#1054#1061#1056#1040#1053#1048#1058#1068' '#1056#1045#1047#1059#1051#1068#1058#1040#1058
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = btnSaveClick
  end
  object btnClear: TButton
    Left = 290
    Top = 590
    Width = 240
    Height = 41
    Caption = #1054#1063#1048#1057#1058#1048#1058#1068
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = btnClearClick
  end
  object OpenDialog1: TOpenDialog
    Filter = 'All files (*.*)|*.*'
    Left = 888
    Top = 600
  end
  object SaveDialog1: TSaveDialog
    Filter = 'All files (*.*)|*.*'
    Left = 960
    Top = 600
  end
end
