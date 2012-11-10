object Form2: TForm2
  Left = 202
  Top = 152
  Width = 654
  Height = 464
  Caption = 'PAlign2'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object RichEdit1: TRichEdit
    Left = 16
    Top = 16
    Width = 614
    Height = 349
    Anchors = [akLeft, akTop, akRight, akBottom]
    Color = clMenu
    Lines.Strings = (
      
        'The Palign2 program is a utility to help you align your polar mo' +
        'unt telescope. Given the coordinates '
      
        'of two stars and the error you found in moving from star 1 to st' +
        'ar 2, the program will compute the error '
      
        'in the azimuth and elevation of the telescope'#39's mount. This is t' +
        'he information you need to tweak the '
      
        'mounting alignment. If you have a Meade LX-200 telescope the pro' +
        'gram is able to automate the '
      
        'moving of your scope and reading of its current position, making' +
        ' the process even faster.'
      ''
      
        'Most mount alignment procedures require you to find Polaris or h' +
        'ave a view of the horizon. This utility '
      
        'does not need that, though the precision is improved the farther' +
        ' apart star 1 and star 2 are located. '
      
        'Alignment becomes an interative process, each step giving you ad' +
        'vice on how to adjust the '
      
        'telescopes mounting. I'#39've been able to adjust my telescope mount' +
        ' to within an arcminute working '
      
        'with 2 stars in the constellation Leo, which is all I can see th' +
        'rough the trees of my viewing site.'
      ''
      
        'The formulas for translating the RA/Dec error to mount zimuth/el' +
        'evation were published by Ralph '
      
        'Pass: "2 star Polar Alignment" (http://rppass.com/align.pdf) The' +
        ' program offered here merely '
      
        'implements the formulas in a format that is relativly easy to us' +
        'e. Thank you Ralph!'
      ''
      
        'The program is offered as freeware with the usual lack of any wa' +
        'rranty and advisement that you use '
      
        'it at your own risk. Be careful of any software that is going to' +
        ' slew your telescope, keeping your hand '
      
        'at the power cutoff until you get comfortable with the program a' +
        'nd learn how to use it and trust it.'
      ''
      
        'I would ask that if you use it, please drop me a note. Kudos and' +
        ' complaints and suggestions for '
      
        'improvements should be sent me, George Silvis, at PAlign2@GASilv' +
        'is.net .'
      ''
      ''
      ''
      'Notes on using the program:'
      ''
      
        'The program has two Modes: If "TestMode" is checked, the program' +
        ' does not attempt to control '
      
        'your telescope via the serial port. You enter the the RA/Dec err' +
        'or you observed swinging from star 1 '
      
        'to star 2, input the sidereal time and hit Button 3 to have the ' +
        'error computed '
      ''
      
        'If "TestMode" is not checked then you are in Automatic mode and ' +
        'the program will communicate '
      'with the telescope if it uses the Meade LX200 interface.'
      ''
      'preparation:'
      '- Your telescope should have its observing location set.'
      '- Your telescope should have its sidereal time set.'
      
        '- Identify the 2 stars that you will be using. Input their coord' +
        'inates into the form or select the star by the '
      'LX200 number. '
      ''
      'process:'
      
        '1- Button 1 will command the scope to goto the coordinates of st' +
        'ar 1.'
      '2- Move the scope manually till it is pointing at star 1.'
      
        '3- Button 2 will sync the scope to the star 1 coordinates and th' +
        'en slew to the coordinates of star 2'
      '4- Move the scope manually till it is pointing at star 2.'
      
        '5- Button 3 will read the scopes postion, compute the observatio' +
        'n error and then compute the '
      'mounting error.'
      
        '6- Now to continue you hit the "Swap star" key. Since you are ne' +
        'ar star 2 it makes sense to treat that '
      'a the star 1 now on this interation. Then go to step 2 above.'
      ''
      ''
      ''
      'tips:'
      
        '- In TestMode you can work in Hour Angle instead of Right Acensi' +
        'on: just leave Local Sidereal Time '
      'set to 0.'
      
        '- The star coordinates can be selected by Meade Star number if y' +
        'ou have the file LX334str.ecu in the '
      
        'same file directory as the Palign2 program. You can get this fil' +
        'e here: '
      
        'http://members.home.net/michaeljcook/ecu/ "Meade LX200 Alignment' +
        ' Star Catalogue (for V 3.34L '
      'firmware)"'
      
        '- The "determinant" field gives you a measure of how good a choi' +
        'ce you have made for your two '
      
        'stars. If they'#39're right next to each other, the determinant will' +
        ' be very small. If its smaller than 0.2, you '
      
        'should try again. According to Ralph, "Note that you should avoi' +
        'd stars with similar hour angles, '
      
        'stars close to the celestial equator, and stars whose declinatio' +
        'ns are close to negative of each '
      
        'other. Each of these factors makes the determainte 0 or close to' +
        ' 0."')
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Button1: TButton
    Left = 288
    Top = 376
    Width = 75
    Height = 41
    Caption = 'Okay'
    TabOrder = 1
    OnClick = Button1Click
  end
end
