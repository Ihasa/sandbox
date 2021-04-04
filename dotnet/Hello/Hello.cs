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
                ExBook book = new ExBook("sample.xlsx");

                //シート名からシート取得
                var sheet = book.GetSheet( "newSheet" );

                //セルに設定
                WriteCell( sheet, 0, 0, "0-0" );
                WriteCell( sheet, 1, 1, "1-1" );
                WriteCell( sheet, 0, 3, 100 );
                WriteCell( sheet, 0, 4, DateTime.Today );

                //日付表示するために書式変更
                var style = book.GetStyle();
                WriteStyle( sheet, 0, 4, style );

                //ブックを保存
                book.SaveBookAs("sample2.xlsx");

            }
            catch( Exception ex ) {
                Console.WriteLine( ex );
            }
        }

                //セル設定(文字列用)
        public static void WriteCell( ISheet sheet, int columnIndex, int rowIndex, string value )
        {
            var row = sheet.GetRow( rowIndex ) ?? sheet.CreateRow( rowIndex );
            var cell = row.GetCell( columnIndex ) ?? row.CreateCell( columnIndex );

            cell.SetCellValue( value );
        }

        //セル設定(数値用)
        public static void WriteCell( ISheet sheet, int columnIndex, int rowIndex, double value )
        {
            var row = sheet.GetRow( rowIndex ) ?? sheet.CreateRow( rowIndex );
            var cell = row.GetCell( columnIndex ) ?? row.CreateCell( columnIndex );

            cell.SetCellValue( value );
        }

        //セル設定(日付用)
        public static void WriteCell( ISheet sheet, int columnIndex, int rowIndex, DateTime value )
        {
            var row = sheet.GetRow( rowIndex ) ?? sheet.CreateRow( rowIndex );
            var cell = row.GetCell( columnIndex ) ?? row.CreateCell( columnIndex );

            cell.SetCellValue( value );
        }

        //書式変更
        public static void WriteStyle( ISheet sheet, int columnIndex, int rowIndex, ICellStyle style )
        {
            var row = sheet.GetRow( rowIndex ) ?? sheet.CreateRow( rowIndex );
            var cell = row.GetCell( columnIndex ) ?? row.CreateCell( columnIndex );

            cell.CellStyle = style;
        }

        static void createNewSample(){
            string filePath = "sample.xlsx";

            //ブック作成
            var book = ExBook.CreateNew( filePath );

            //シート無しのexcelファイルは保存は出来るが、開くとエラーが発生する
            book.AddSheet( "newSheet" );

            //ブックを保存
            book.SaveBook();
        }
    }
}
