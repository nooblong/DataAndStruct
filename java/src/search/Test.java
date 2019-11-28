package search;

import java.awt.*;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.Transferable;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.util.concurrent.TimeUnit;

public class Test {

    public static final String BROWSER_PATH = "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe";

    public static String getText() {
        String s = "";
        Clipboard clipboard = Toolkit.getDefaultToolkit().getSystemClipboard();
        Transferable transfer = clipboard.getContents(null);
        if (transfer != null) {
            if (transfer.isDataFlavorSupported(DataFlavor.stringFlavor)) {
                try {
                    s = (String) transfer.getTransferData(DataFlavor.stringFlavor);
                } catch (Exception e) {
                    System.err.println("not string");
                }
            }
        }
        return s;
    }

    public static void browserChrome(String s) {
        String osName = System.getProperty("os.name", "");
        if (osName.startsWith("Windows")) {
            try {
                ProcessBuilder proc = new ProcessBuilder(BROWSER_PATH, s);
                proc.start();
            } catch (IOException e) {
                System.err.println("can not open url");
            }
        }
    }

    public static void main(String[] args) {
        String old = getText();
        String s = getText();
        while (true) {
            if (old.equals(s)) {
                try {
                    s = getText();
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            } else {
                try {
                    browserChrome("https://zhidao.baidu.com/search?lm=0&rn=10&pn=0&fr=search&ie=gbk&word=" + URLEncoder.encode(s,"GBK"));
                } catch (UnsupportedEncodingException e) {
                    e.printStackTrace();
                }
                old = s;
                System.out.println("search " + s);
            }
        }
    }
}
