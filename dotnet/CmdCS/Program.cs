using System;
using System.IO;
using CmdLib;

namespace CmdCS
{
    class Program
    {
        static void Main(string[] args)
        {
            TextCmds cmds = new TextCmds("./latest.log");
            cmds.csGrep(".", "n");
            using (StreamWriter wr = new StreamWriter(File.Open("./hogehoge.txt",FileMode.CreateNew))){
                //wr.AutoFlush = true;
                try{
                    Console.WriteLine(wr.AutoFlush);
                    wr.WriteLine("HOHOHO.");
                    //throw new Exception();
                    //wr.Dispose();
                }catch(Exception e){
                    Console.WriteLine(e);
                }
            }
        }
    }
}
