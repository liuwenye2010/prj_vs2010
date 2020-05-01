using System;
using System.Windows;
using System.Data;
using System.Xml;
using System.Configuration;
/// johl
using System.Text;
using System.Collections.Generic;
using System.Timers;

namespace EightBall
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>

    public partial class App : System.Windows.Application
    {
        Dictionary<string,int> things = new   Dictionary<string,int>(); 
        things.Add("greee",29); 
        int intval = 30; 
        StringBuilder sb = new StringBuilder();
        sb.Append("orgin");
        sb.AppendFormat("=={0}",intval);
        ///System.Random
    }
}