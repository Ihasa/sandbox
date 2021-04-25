﻿using System;
using System.IO;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace CmdCS
{
    class Program
    {
        static void Main(string[] args)
        {
            csGrep("\\[17:", "../grepstudy/latest.log", "n");
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

        static List<string> findList;
        static void csGrep(string pat, string filePath,  string option){
            findList = new List<string>();
            using(StreamReader sr = new StreamReader(filePath)){
                int rowNum = 1;
                while(!sr.EndOfStream){
                    string s = sr.ReadLine();
                    Regex exp = new Regex(pat);
                    if(exp.IsMatch(s)){
                        string res = (option == "n") ? rowNum + ":" + s : s;
                        findList.Add(res);
                    }
                    rowNum++;
                }
            }

            if(option == "c"){
                Console.WriteLine(findList.Count);
            } else {
                foreach(string s in findList){
                    Console.WriteLine(s);
                }
            }
        }
    }
}
