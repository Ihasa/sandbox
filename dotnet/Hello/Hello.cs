using System;
using System.IO;
using NPOI.SS.UserModel;
using NPOI.HSSF.UserModel;
using NPOI.XSSF.UserModel;
// .NET FrameworkのコンパイラならC:/Windows/Microsoft.NET/Framework64/[バージョン]/にパスを通すだけ
// .NET Core使うなら→https://docs.microsoft.com/ja-jp/dotnet/core/get-started
//  dotnet new --output プロジェクト名
//  dotnet run --project プロジェクト名
//  NPOI使って空xlsx作るexample→ https://qiita.com/hukatama024e/items/37427f2578a8987645dd

namespace hoge
{
    public class Hello
    {
        static void Main()
        {
            try {
                string filePath = "sample.xlsx";

                //ブック作成
                var book = ExBook.CreateNew( filePath );

                //シート無しのexcelファイルは保存は出来るが、開くとエラーが発生する
                book.AddSheet( "newSheet" );

                //ブックを保存
                book.SaveBook();
            }
            catch( Exception ex ) {
                Console.WriteLine( ex );
            }
        }
    }
}
